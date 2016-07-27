/**
 * @file time1.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-07-25
 */

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
using std::cout;
using std::endl;

int main( int argc, char* argv[] )
{
	time_t _t = time(NULL);
	printf( "UTC:	%s", asctime( gmtime(&_t) ) );
	printf( "local:	%s", asctime( localtime(&_t) ) );
	
	time_t _temp = _t - _t % 86400;
	printf( "UTC:	%s", asctime( gmtime(&_temp) ) );
	printf( "local:	%s", asctime( localtime(&_temp) ) );

	time_t _temp1 = _temp + 43200;
	printf( "UTC:	%s", asctime( gmtime(&_temp1) ) );
	printf( "local:	%s", asctime( localtime(&_temp1) ) );

	return 0;
}
