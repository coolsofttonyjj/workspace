/**
 * @file test.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-04-20
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <unistd.h>

using namespace std;

struct Nonumber
{
};

struct Nonumber1
{
	int a[0];
};

struct Nonumber2
{
	char c;
	char c1;
	char c2;
	char c3;
	int a[0];
};

enum Flag
{
	A = 100,
	B = 200,
	C = 300,
};

bool Judge( Flag _value )
{
	int abc = 900;
	abc += _value;
	cout << abc << endl;
	return true;
}

int main( int argc, char* argv[] )
{
	int a = 1;
	cout << (++a ? a : 1) << endl;
	
	std::vector<int> _vec;
	for( int i = 0 ; i < 10; ++i )
	{
		_vec.push_back( i );
	}


	for( auto it = _vec.begin(); it != _vec.end(); ++it )
	{
		if( *it == 2 )
		{
			_vec.erase( it );
			break;
		}
	}

	cout << pow( 2, 5 ) << endl;

	cout << sizeof(char) << endl;
	cout << sizeof(Nonumber) << endl;
	cout << sizeof(Nonumber1) << endl;
	cout << sizeof(Nonumber2) << endl;

	int _cc = TEMP_FAILURE_RETRY(1);
	cout << _cc << endl;
	
	int _dd = ({ long int __result; do __result = (long int)(22); while (__result == -1L && errno == EINTR); __result; });
	cout << _dd << endl;

	int _ee = ({ 2; 3;  });
	cout << _ee << endl;
  
	Judge( Flag::A );

	return 0;
}
