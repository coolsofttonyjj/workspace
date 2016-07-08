/**
 * @file time.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-05-31
 */

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <string>
using std::cout;
using std::endl;

#define DC(x) #x

int main( int argc, char* argv[] )
{
	time_t _t = time(NULL);
	printf( "UTC:	%s", asctime( gmtime(&_t) ) );
	printf( "local:	%s", asctime( localtime(&_t) ) );

	time_t _temp = _t - _t % 86400;
	//_t -= _temp;
	printf( "UTC:	%s", asctime( gmtime(&_temp) ) );
	printf( "local:	%s", asctime( localtime(&_temp) ) );

	struct timespec tv;
	clock_gettime( CLOCK_REALTIME, &tv );
	unsigned long long retval = 0LL;
	retval = tv.tv_sec;
	retval *= 1000L;
	retval += ( tv.tv_nsec / 1000000L );
	cout << retval << endl;
	cout << _t << endl;
	cout << tv.tv_sec << endl;
	cout << tv.tv_nsec << endl;
	cout << tv.tv_nsec / 1000000L << endl;

	cout << __FUNCTION__ << endl;
	cout << __LINE__ << endl;
	cout << __FILE__ << endl;
	cout << __DATE__ << endl;
	cout << __TIME__ << endl;
	cout << __STDC__ << endl;

	cout << DC(aafaf) << endl;

	return 0;
}
