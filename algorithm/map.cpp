/**
 * @file map.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-06-21
 */

#include <iostream>
#include <map>

using std::cout;
using std::endl;

struct Keys
{
	Keys( int _a, int _b ) : a( _a ), b( _b )
	{
	
	}

	Keys() : a( 0 ), b( 0 )
	{
	
	}

	bool operator < ( const Keys& _other  ) const
	{
		if( a < _other.a )
		{
			return true;
		}
		return false;
	}

	void Set1()
	{
		Set();
	}

	void Set() const
	{
	}

	int a;
	int b;
};

int main( int argc, char* argv[] )
{
	Keys k(10,10);
	std::map< Keys, int > _map;
	_map[k] = 10;
	return 0;
}
