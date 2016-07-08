/**
 * @file helloworld.cpp
 * @brief	
 * @author 
 * @version TonyJJ
 * @date 2016-03-09
 */

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
using namespace std;

bool g_b = true;

void HupHandler( int signum )
{
	cout << signum << endl;
}

void StopHandle( int signum )
{
	g_b = false;
}

void MySigaction1()
{
	struct sigaction sig;
	sigemptyset( &sig.sa_mask );
	sig.sa_handler = HupHandler;
	sig.sa_flags = SA_NOMASK;

	sigaction( SIGINT, &sig, NULL );
	sigaction( SIGQUIT, &sig, NULL );
	sigaction( SIGABRT, &sig, NULL );
	sigaction( SIGTERM, &sig, NULL );

	sig.sa_handler = StopHandle;
	sigaction( SIGHUP, &sig, NULL );

	while ( g_b )
	{
		sleep( 300 );
	}

	cout << "handle end" << endl;
}
///////////////////////////////////////////////////////

void sig_usr( int signum )
{
	if ( signum == SIGUSR1 )
	{
		printf( "SIGUSR1 received\n" );
	}
	else if ( signum == SIGUSR2 )
	{
		printf( "SIGUSR2 received\n" );
	}
	else
	{
		printf( "signal %d received\n", signum );
	}
}

void MySigaction2()
{
	char buf[512];
	int n = 0;
	struct sigaction sa_usr;
	sa_usr.sa_flags = 0;
	//sa_usr.sa_flags = SA_RESTART;
	sa_usr.sa_handler = sig_usr;
	sigaction( SIGUSR1, &sa_usr, NULL );
	sigaction( SIGUSR2, &sa_usr, NULL );

	printf( "My PID is %d\n", getpid() );

	while( 1 )
	{
		if ( ( n = read( STDIN_FILENO, buf, 511 ) )  == -1 )
		{
			if ( errno == EINTR )
			{
				printf( "read is interrupted by signal\n" );
			}
		}
		else
		{
			buf[n] = '\0';
			printf( "%d bytes read: %s", n, buf );
		}
	}
}

int main( int argc, char* argv[] )
{
	MySigaction2();
	return 0;
}

