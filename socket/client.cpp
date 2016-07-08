/**
 * @file client.cpp
 * @brief	
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
#include <vector>

int main( int argc, char* argv[] )
{
	int sockfd = 0;
	char buffer[1024];
	struct sockaddr_in server_addr;
	struct hostent* host;
	int portnumber = 8888;
	int nbytes = 0;

	//if( argc != 2 )
	//{
		//fprintf( stderr, "Usage:%s hostname portnumber\n", argv[0] );
		//exit(1);
	//}

	//if( (host = gethostbyname(argv[1])) == NULL )
	//{
		//fprintf( stderr, "Gethostbyname error\n" );
		//exit(1);
	//}

	//if( (portnumber = atoi(argv[2])) < 0 )
	//{
		//fprintf( stderr, "Usage:%s hostname portnumber\n", argv[0] );
		//exit(1);
	//}

	//客户端建立sockfd
	if( (sockfd = ::socket(AF_INET, SOCK_STREAM, 0)) == -1 )
	{
		fprintf( stderr, "Socket Error:%s\n", strerror( errno ) );
		exit(1);
	}

	//客户端填充服务器数据
	bzero( &server_addr, sizeof(server_addr) );
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons( portnumber );
	//server_addr.sin_addr = *((struct in_addr*)host->h_addr);
	//server_addr.sin_addr.s_addr = inet_addr( argv[1] );
	server_addr.sin_addr.s_addr = htonl( INADDR_ANY );

	//客户端发起连接请求
	if( ::connect( sockfd, (struct sockaddr*)(&server_addr), sizeof(struct sockaddr) ) == -1 )
	{
		fprintf( stderr, "Connect Error:%s\n", strerror( errno ) );
		exit(1);
	}

	//fprintf( stderr, "hahaha\n" );

	//连接成功
	if( (nbytes = ::read( sockfd, buffer, 1024 )) == -1 )
	{
		fprintf( stderr, "Read Error:%s\n", strerror( errno ) );
		exit(1);
	}

	buffer[nbytes] = '\0';
	printf( "I have received:%s\n", buffer );
	//结束通讯
	close(sockfd);
	exit(0);

	return 0;
}

