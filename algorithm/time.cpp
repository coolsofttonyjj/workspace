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
#include <sstream>
using std::cout;
using std::endl;

long g_Timezone = 0;

const std::string& GetLocalTZ()
{
	static std::string str;
	static bool init = false;
	if( !init )
	{
		std::ostringstream so;
		tzset();
		if( g_Timezone == 0 )
		{
			g_Timezone = ::timezone;
		}

		so << ::tzname[0] << ::timezone / 3600;
		str = so.str();
		init = true;
	}
	return str;
}

void GetLocalTime( tm& tv1, time_t _time )
{
	_time -= g_Timezone;
	gmtime_r( &_time, &tv1 );
	printf( "Local UTC:	%s", asctime( gmtime(&_time) ) );
	//printf( "Local local:	%s", asctime( localtime(&_time) ) );
}

int main( int argc, char* argv[] )
{

	std::string str = GetLocalTZ();
	cout << str << endl;

	time_t _t = time(NULL);
	printf( "UTC:	%s", asctime( gmtime(&_t) ) );
	printf( "local:	%s", asctime( localtime(&_t) ) );

	time_t _temp = _t - _t % 86400;
	//_t -= _temp;
	printf( "UTC:	%s", asctime( gmtime(&_temp) ) );
	printf( "local:	%s", asctime( localtime(&_temp) ) );
	
	time_t _temptime = (_t / 86400) * 86400;
	printf( "UTC:	%s", asctime( gmtime(&_temptime) ) );
	printf( "local:	%s", asctime( localtime(&_temptime) ) );

	time_t _abc = 1476029708;
	printf( "UTC:	%s", asctime( gmtime(&_abc) ) );
	printf( "local:	%s", asctime( localtime(&_abc) ) );

	tm _tm;
	GetLocalTime( _tm, _abc );

	//tm* _tm = localtime( &_t );
	//_tm->tm_hour = 0;
	//_tm->tm_min = 5;
	//_tm->tm_sec = 0;
	//time_t _uptime = mktime( _tm );
	//_temp = _uptime - _uptime % 86400;
	//printf( "UTC:	%s", asctime( gmtime(&_uptime) ) );
	//printf( "local:	%s", asctime( localtime(&_uptime) ) );
	//printf( "UTC:	%s", asctime( gmtime(&_temp) ) );
	//printf( "local:	%s", asctime( localtime(&_temp) ) );

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

	return 0;
}
