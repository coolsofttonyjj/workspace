/**
 * @file epollClient.cpp
 * @brief	epoll客户端
 * @author 	TonyJJ
 * @version 1.1
 * @date 2016-04-04
 */

#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define IPADDRESS	"127.0.0.1"
#define	PORT		8787
#define	MAXSIZE		1024
#define	LISTENQ		5
#define	FDSIZE		1000
#define	EPOLLEVENTS	100

//创建套接字并进行绑定
static void handle_connect( int _sockfd );

//时间处理函数
static void handle_events( int _epollfd, struct epoll_event* _events, int _num, int _sockfd, char* _buf );

//读处理
static void do_read( int _epollfd, int _fd, int _sockfd, char* _buf );

//写处理
static void do_write( int _epollfd, int _fd, int _sockfd, char* _buf );

//添加事件
static void add_event( int _epollfd, int _fd, int _state );

//修改事件
static void modify_event( int _epollfd, int _fd, int _state );

//删除事件
static void delete_event( int _epollfd, int _fd, int _state );

int main( int argc, char* argv[] )
{
	int sockfd = 0;
	struct sockaddr_in servaddr;
	sockfd = ::socket( AF_INET, SOCK_STREAM, 0 );
	bzero( &servaddr, sizeof( servaddr ) );

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons( PORT );
	inet_pton( AF_INET, IPADDRESS, &servaddr.sin_addr );
	::connect( sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr) );
	//处理连接
	handle_connect( sockfd );
	close( sockfd );
	return 0;
}

static void handle_connect( int _sockfd )
{
	int epollfd = 0;
	struct epoll_event events[EPOLLEVENTS];
	char buff[MAXSIZE];
	int ret = 0;
	epollfd = ::epoll_create( FDSIZE );
	add_event( epollfd, STDIN_FILENO, EPOLLIN );
	for( ; ; )
	{
		ret = ::epoll_wait( epollfd, events, EPOLLEVENTS, -1 );
		handle_events( epollfd, events, ret, _sockfd, buff );
	}
}

static void handle_events( int _epollfd, struct epoll_event* _events, int _num, int _sockfd, char* _buf )
{
	int fd = 0;
	for( int i = 0; i < _num; ++i )
	{
		fd = _events[i].data.fd;
		if( _events[i].events & EPOLLIN )
		{
			do_read( _epollfd, fd, _sockfd, _buf );
		}
		else if( _events[i].events & EPOLLOUT )
		{
			do_write( _epollfd, fd, _sockfd, _buf );
		}
	}
}

static void do_read( int _epollfd, int _fd, int _sockfd, char* _buf )
{
	int nread = ::read( _fd, _buf, MAXSIZE );
	if( nread == -1 )
	{
		perror( "read error:" );
		::close( _fd );
	}
	else if( nread == 0 )
	{
		fprintf( stderr, "client close.\n" );
		::close( _fd );
	}
	else
	{
		if( _fd == STDIN_FILENO )
		{
			add_event( _epollfd, _sockfd, EPOLLOUT );
		}
		else
		{
			delete_event( _epollfd, _sockfd, EPOLLIN );
			add_event( _epollfd, STDOUT_FILENO, EPOLLOUT );
		}
	}
}

//写处理
static void do_write( int _epollfd, int _fd, int _sockfd, char* _buf )
{
	int nwrite = ::write( _fd, _buf, strlen(_buf) );
	if( nwrite == -1 )
	{
		perror( "write error:" );
		::close( _fd );
	}
	else
	{
		if( _fd == STDOUT_FILENO )
		{
			delete_event( _epollfd, _fd, EPOLLOUT );
		}
		else
		{
			modify_event( _epollfd, _fd, EPOLLIN );
		}
	}
	::memset( _buf, 0, MAXSIZE );
}

static void add_event( int _epollfd, int _fd, int _state )
{
	struct epoll_event ev;
	ev.events = _state;
	ev.data.fd = _fd;
	::epoll_ctl( _epollfd, EPOLL_CTL_ADD, _fd, &ev );
}

static void modify_event( int _epollfd, int _fd, int _state )
{
	struct epoll_event ev;
	ev.events = _state;
	ev.data.fd = _fd;
	::epoll_ctl( _epollfd, EPOLL_CTL_DEL, _fd, &ev );
}

static void delete_event( int _epollfd, int _fd, int _state )
{
	struct epoll_event ev;
	ev.events = _state;
	ev.data.fd = _fd;
	::epoll_ctl( _epollfd, EPOLL_CTL_MOD, _fd, &ev );
}

