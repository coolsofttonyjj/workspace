/**
 * @file tcpServer.cpp
 * @brief	简单tcp协议	
 * @author 	TonyJJ
 * @version 1.1
 * @date 2016-04-01
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
//#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <signal.h>

bool g_bool = true;

void Signal_Action( int _sig, siginfo_t* _info, void* _myact  )
{
	fprintf( stderr, "收到中断信号\n" );
	g_bool = false;
}

void Signal_Handler( int _sig )
{
	fprintf( stderr, "收到中断信号1\n" );
	g_bool = false;
}

int main( int argc, char* argv[] )
{
	//注册信号
	struct sigaction act;
	sigemptyset( &act.sa_mask );
	//act.sa_sigaction = Signal_Action;
	act.sa_handler = Signal_Handler;
	act.sa_flags = 0;
	if( sigaction( SIGINT, &act, NULL ) < 0 )
	{
		fprintf( stderr, "signal error\n" );
		exit(0);
	}

	int sockfd = 0;
	int new_fd = 0;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	socklen_t sin_size = 0;
	int portnumber = 0;
	char hello[] = "Hello! Are You Fine?\n";

	if ( argc != 2 )
	{
		fprintf( stderr, "Usage:%s portnumber\n", argv[0] );
		return 1;
	}

	if ( (portnumber = atoi( argv[1])) < 0 )
	{
		fprintf( stderr, "Usage:portnumber\n" );
		return 2;
	}

	//服务器建立sokect描述符
	if( (sockfd = ::socket( AF_INET, SOCK_STREAM, 0 )) == -1  )
	{
		fprintf( stderr, "socket error:%s\n", strerror(errno) );
		return 3;
	}

	//填充sockaddr结构
	bzero( &server_addr, sizeof(server_addr) );
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl( INADDR_ANY );
	server_addr.sin_port = htons( portnumber );

	//绑定sockfd描述符
	if( ::bind( sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr) ) == -1 )
	{
		fprintf( stderr, "bind error:%s\n", strerror(errno) );
		return 4;
	}

	//监听sockfd描述符
	if( ::listen( sockfd, 5 ) == -1 )
	{
		fprintf( stderr, "listen error:%s\n", strerror(errno) );
		return 5;
	}

	//fprintf( stderr, "lalalalalalal\n" );
	while( g_bool )
	{
		//服务器阻塞，等待客户端建立连接
		sin_size = sizeof( struct sockaddr_in );
		if( (new_fd = ::accept( sockfd, (struct sockaddr*)&client_addr, &sin_size)) == -1 )
		{
			fprintf( stderr, "accept error:%s\n", strerror( errno ) );
			break;
		}
		inet_ntoa( client_addr.sin_addr );
		if( ::write( new_fd, hello, strlen(hello) ) == -1 )
		{
			fprintf( stderr, "write error:%s\n", strerror( errno ) );
			return 6;
		}

		close(new_fd);
	}

	fprintf( stderr, "服务结束\n" );
	close( sockfd );
	return 0;
}
