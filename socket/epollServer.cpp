/**
 * @file epollServer.cpp
 * @brief	epoll服务器
 * @author 	TonyJJ
 * @version 1.1
 * @date 2016-04-04
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <sys/types.h>

#define IPADDRESS	"127.0.0.1"
#define	PORT		8787
#define	MAXSIZE		1024
#define	LISTENQ		5
#define	FDSIZE		1000
#define	EPOLLEVENTS	100

//创建套接字并进行绑定
static int socket_bind( const char* _ip, int _port );

//IO多路复合epoll
static void do_epoll( int _listenfd );

//时间处理函数
static void handle_events( int _epollfd, struct epoll_event* _events, int _num, int _listenfd, char* _buf );

//处理接收到的连接
static void handle_accept( int _epollfd, int _listenfd );

//读处理
static void do_read( int _epollfd, int _fd, char* _buf );

//写处理
static void do_write( int _epollfd, int _fd, char* _buf );

//添加事件
static void add_event( int _epollfd, int _fd, int _state );

//修改事件
static void modify_event( int _epollfd, int _fd, int _state );

//删除事件
static void delete_event( int _epollfd, int _fd, int _state );

//main函数
int main( int argc, char* argv[] )
{
	int listenfd = socket_bind( IPADDRESS, PORT );
	::listen( listenfd, LISTENQ );
	do_epoll( listenfd );
	return 0;
}

static int socket_bind( const char* _ip, int _port )
{
	int listenfd = 0;
	struct sockaddr_in servaddr;
	listenfd = ::socket( AF_INET, SOCK_STREAM, 0 );
	if( listenfd == -1 )
	{
		perror( "socket error:" );
		exit(1);
	}

	bzero( &servaddr, sizeof(servaddr) );
	servaddr.sin_family = AF_INET;
	//server_addr.sin_addr.s_addr = htonl( INADDR_ANY );
	inet_pton( AF_INET, _ip, &servaddr.sin_addr );
	servaddr.sin_port = htons( _port );
	if( ::bind( listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr) ) == -1 )
	{
		perror( "bind error:" );
		exit(1);
	}
	return listenfd;
}

static void do_epoll( int _listenfd )
{
	int epollfd = 0;
	struct epoll_event events[EPOLLEVENTS];
	int ret = 0;
	char buff[MAXSIZE];
	::memset( buff, 0, MAXSIZE );
	//创建一个描述符
	epollfd = ::epoll_create( FDSIZE );
	//添加监听描述符事件
	add_event( epollfd, _listenfd, EPOLLIN );

	for( ; ; )
	{
		//获取已经准备好的描述事件
		ret = ::epoll_wait( epollfd, events, EPOLLEVENTS, -1 );

		handle_events( epollfd, events, ret, _listenfd, buff );
	}
	::close( epollfd );
}

static void handle_events( int _epollfd, struct epoll_event* _events, int _num, int _listenfd, char* _buf )
{
	int fd = 0;
	for( int i = 0; i < _num; ++i )
	{
		fd = _events[i].data.fd;
		//根据描述符的类型和事件类型进行处理
		if( (fd == _listenfd) && (_events[i].events & EPOLLIN) )
		{
			handle_accept( _epollfd, _listenfd );
		}
		else if( _events[i].events & EPOLLIN )
		{
			do_read( _epollfd, fd, _buf );
		}
		else if( _events[i].events & EPOLLOUT )
		{
			do_write( _epollfd, fd, _buf );
		}
	}
}

static void handle_accept( int _epollfd, int _listenfd )
{
	int clifd = 0;
	struct sockaddr_in cliaddr;
	socklen_t cliaddrlen = sizeof(sockaddr_in);
	clifd = ::accept( _listenfd, (struct sockaddr*)&cliaddr, &cliaddrlen );
	if( clifd == -1 )
	{
		perror( "accept error:" );
	}
	else
	{
		printf( "accept a new client:%s:%d\n", inet_ntoa(cliaddr.sin_addr), cliaddr.sin_port );
		//添加一个客户端描述符和事件
		add_event( _epollfd, clifd, EPOLLIN );
	}
}

static void do_read( int _epollfd, int _fd, char* _buf )
{
	int nread = ::read( _fd, _buf, MAXSIZE );
	if( nread == -1 )
	{
		perror( "read error:" );
		::close( _fd );
		delete_event( _epollfd, _fd, EPOLLIN );
	}
	else if( nread == 0 )
	{
		fprintf( stderr, "client close.\n" );
		::close( _fd );
		delete_event( _epollfd, _fd, EPOLLIN );
	}
	else
	{
		printf( "read message is : %s", _buf );
		modify_event( _epollfd, _fd, EPOLLIN );
	}
}

static void do_write( int _epollfd, int _fd, char* _buf )
{
	int nwrite = ::write( _fd, _buf, strlen(_buf) );
	if( nwrite == -1 )
	{
		perror( "write error:" );
		::close( _fd );
		delete_event( _epollfd, _fd, EPOLLOUT );
	}
	else
	{
		modify_event( _epollfd, _fd, EPOLLOUT );
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
