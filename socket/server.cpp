/**
 * @file server.cpp
 * @brief	简单TCP连接
 * @author 
 * @version 
 * @date 2016-03-23
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <map>

int main( int argc, char* argv[] )
{
	int sockfd = 0;
	int new_fd = 0;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	socklen_t sin_size = 0;
	int portnumber = 8888;
	char hello[] = "Hello! Are You Fine?\n";

	//if( argc != 2 )
	//{
		//fprintf( stderr, "Usage:%s portnumber1\n", argv[0] );
		//exit(1);
	//}

	//if( ( portnumber = atoi(argv[1]) < 0 ) ) 
	//{
		//fprintf( stderr, "Usage:%s portnumber2\n", argv[0] );
		//exit(1);
	//}

	//服务器建立sockfd
	if( (sockfd = ::socket(AF_INET, SOCK_STREAM, 0)) == -1 )
	{
		fprintf( stderr, "Socket error:%s\n", strerror(errno));
		exit(1);
	}

	//填充sockaddr结构
	bzero( &server_addr, sizeof( struct sockaddr_in ) );
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl( INADDR_ANY );
	//server_addr.sin_addr.s_addr = inet_addr( argv[1] );
	server_addr.sin_port = htons( portnumber );

	//捆绑 sockfd
	if( ::bind( sockfd, (struct sockaddr*)( &server_addr ), sizeof(struct sockaddr) ) == -1 )
	{
		fprintf( stderr, "Bind error:%s\n", strerror(errno) );
		exit(1);
	}

	//监听 sockfd
	if( ::listen( sockfd, 5 ) == -1 )
	{
		fprintf( stderr, "Listen error:%s\n", strerror( errno ) );
		exit(1);
	}

	while( 1 )
	{
		//服务器阻塞，知道客户端建立连接
		sin_size = sizeof( struct sockaddr_in );
		bzero( &client_addr, sizeof(struct sockaddr_in) );
		if( ( new_fd = ::accept(sockfd, (struct sockaddr*)(&client_addr), &sin_size) ) == -1 )
		{
			fprintf( stderr, "Accept error:%s\n", strerror(errno) );
			exit(1);
		}

		fprintf( stderr, "Server get connection from %s\n", inet_ntoa( client_addr.sin_addr ) );
		if( ::write( new_fd, hello, strlen(hello) ) == -1 )
		{
			fprintf( stderr, "Write error:%s\n", strerror( errno ) );
			exit(1);
		}

		//通讯结束
		close(new_fd);
	}

	close(sockfd);
	exit(0);

	return 0;
}

