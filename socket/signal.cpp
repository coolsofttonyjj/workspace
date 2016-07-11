/**
 * @file signal.cpp
 * @brief	简单信号处理
 * @author TonyJJ
 * @version 1.1
 * @date 2016-04-03
 */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void sig_user( int signum )
{
	if( signum == SIGUSR1 )
	{
		printf( "SIGUSR1 received\n" );
	}
	else if( signum == SIGUSR2 )
	{
		printf( "SIGUSR2 received\n" );
	}
	else
	{
		printf( "signal %d received\n" );
	}
}

int main( int argc, char* argv[] )
{
	char buff[512];
	int n = 0;
	struct sigaction sa_user;
	sa_user.sa_flags = 0;
	sa_user.sa_handler = sig_user;
	sigaction( SIGUSR1, &sa_user, NULL );

	sa_user.sa_flags = SA_RESTART;
	sa_user.sa_handler = sig_user;
	sigaction( SIGUSR2, &sa_user, NULL );
	
	printf( "My PID is %d\n", ::getpid() );
	while( true )
	{
		if( (n = ::read(STDIN_FILENO, buff, 511)) == -1 )
		{
			if( errno == EINTR )
			{
				printf( "read is interrupted by signal\n" );
			}
		}
		else
		{
			buff[n] = '\0';
			printf( "%d bytes read: %s\n", n, buff );
		}
		printf( "hahahahaha\n" );
	}
	return 0;
}
