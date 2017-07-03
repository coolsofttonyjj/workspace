#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string>
using std::cout;
using std::endl;

typedef unsigned int	DWORD;

class ActTimer
{
	public:
		ActTimer() {}
		~ActTimer() {}

		void Init( time_t _startTime, DWORD _duration, DWORD _interval )
		{
			time_t tenyear = 10*365*24*60*60;
			m_StartTime = _startTime;
			m_Duration = _duration ? _duration : tenyear;
			m_Interval = _interval ? _interval : tenyear;
		}

		//是否开始
		bool InTime()
		{
			time_t cur = time(NULL);
			return ( cur < m_StartTime ) ? false : ( ( ( cur - m_StartTime ) % m_Interval ) <= m_Duration );
		}

		//是否结束
		bool IsOver()
		{
			time_t cur = time(NULL);
			if( cur < m_StartTime )
			{
				return false;
			}

			time_t differ = ( cur - m_StartTime ) % m_Interval;
			if( differ <= m_Duration )
			{
				return false;
			}

			return true;
		}

		//下一次活动开始时间
		time_t NextStartTime()
		{
			time_t cur = time( NULL );
			return cur > m_StartTime ? cur - ( (cur - m_StartTime) % m_Interval ) + m_Interval : m_StartTime;
		}

		//开始后，本次活动开始时间
		time_t ThisStartTime()
		{
			time_t cur = time( NULL );
			return cur > m_StartTime ? cur - ( (cur - m_StartTime) % m_Interval ) : 0;
		}

		//活动结束时间
		time_t EndTime()
		{
			time_t cur = time( NULL );
			return cur > m_StartTime ? cur - ( (cur - m_StartTime) % m_Interval ) + m_Duration : m_StartTime + m_Duration;
		}

	private:
		time_t m_StartTime = 0;		//开始时刻
		time_t m_Duration = 0;		//持续时间
		time_t m_Interval = 10*365*24*60*60;		//下次开始时间
};

int main( int argc, char* argv[] )
{
	{
		tzset();
		std::string str = "2017-07-3 12:00:00";
		tm tv;
		time_t beginTime = time(NULL) + 10 * 365 * 24 * 3600;
		if( strptime( str.c_str(), "%Y-%m-%d %H:%M:%S", &tv ) != NULL )
		{
			time_t temp = timegm( &tv );
			if( (time_t)-1 != temp )
			{
				beginTime = temp + timezone;
			}

			ActTimer acttime;
			acttime.Init( beginTime, 24*3600, 48*3600 );
			bool b = acttime.InTime();
			if( b )
			{
				cout << "begin" << endl;
			}
			else
			{
				cout << "no begin" << endl;
			}
		}
	}

	time_t result = time( NULL );
	printf( "%s %ju secs since the Epoch\n", asctime( localtime( &result ) ), (uintmax_t)result );

	return 0;
}
