/**
 * @file bitmap.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-04-15
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <strings.h>
#include <unistd.h>
using namespace std;

#define BITWORD 32
#define TOTAL 10000000

int array[1 + TOTAL /BITWORD];

void set( int _number )
{
	int _index = _number / BITWORD;
	int _pos = _number % BITWORD;
	array[_index] |= ( 1 << _pos );
}

void clr( int _number )
{
	int _index = _number / BITWORD;
	int _pos = _number % BITWORD;
	array[_index] &= ~( 1 << _pos );
}

int test( int _number )
{
	int _index = _number / BITWORD;
	int _pos = _number %  BITWORD;
	return array[_index] & ( 1 << _pos );
}

int main( int argc, char* argv[] )
{
	bzero( array, sizeof(array) );

	for( int i = 0 ; i < 100; ++i )
	{
		set(i);
	}

	int n = 0;
	char buf[128];
	while( 1 )
	{
		if( (n = ::read( STDIN_FILENO, buf, 127 ) ) == -1 )	
		{
		
		}
		else
		{
			buf[n]='\0';
			int number =  atoi( buf );
			if ( test( number ) == 0 )
			{
				cout << "不存在" << endl;
			}
			else
			{
				cout << "存在" << endl;
			}
		}
	}

	return 0;
}
