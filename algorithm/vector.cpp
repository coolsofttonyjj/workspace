/**
 * @file vecotr.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-05-19
 */

#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

using std::vector;
using std::map;
using std::cout;
using std::endl;

class Pet
{
	public:
		Pet() : _vec(9)
		{
		}

		~Pet()
		{
		
		}

		vector<int> _vec;
};

int main( int argc, char* argv[] )
{
	vector<int> _vec;
	for( int i = 0 ; i < 10; ++i )
	{
		_vec.push_back(i);
	}

	cout << _vec.size() << endl;

	{
		auto it = _vec.begin();
		while( it != _vec.end() )
		{
			if( *it % 2 == 0 )
			{
				it = _vec.erase( it );
			}
			else
			{
				++it;
			}
		}
	}

	cout << _vec.size() << endl;

	map< int, int > _map;
	for( int i = 0; i < 10; ++i )
	{
		_map[i] = i;
	}
	cout << _map.size() << endl;

	{
		//auto it = _map.begin();
		//while( it != _map.end() )
		//{
			//if( it->second % 2 == 0 )
			//{
				//it = _map.erase( it );
			//}
			//else
			//{
				//++it;
			//}
		//}

		for( auto it = _map.begin(); it != _map.end(); ++it )
		{
			if( it->second % 2 == 0 )
			{
				it = _map.erase( it );
			}
		}
	}
	cout << _map.size() << endl;


	//vector<int> _vec;
	//for( size_t i = 0 ; i < 10; ++i )
	//{
		//_vec.push_back(i);
	//}

	//_vec.resize(5);

	//for( size_t i = 0; i < _vec.size(); ++i )
	//{
		//cout << _vec[i] << endl;
	//}

	/////////////////////////////////////
	//
	for( int i = 0; i < 20; ++i )
	{
		cout << "*";
	}
	cout << endl;
	vector<int> _tempVec;
	for( int i = 0 ; i < 10; ++i )
	{
		_tempVec.push_back(i);
	}

	unsigned int seed = time(NULL);
	::srandom( seed );

	for( int i = 0 ; i < 3; ++i )
	{
		//int index = (int)(::random() % _tempVec.size());
		//_tempVec.erase( _tempVec.begin() + index );
	}

	//for( auto it : _tempVec )
	//{
		//cout << it << endl;
	//}

	//std::vector<int> _tempVecc;
	//_tempVecc.resize(4);
	//for( auto it : _tempVecc )
	//{
		//cout << it << endl;
	//}

	//std::vector< std::vector<int> > _DoubleVec;
	//_DoubleVec.resize(2);
	//_DoubleVec[0].push_back( 100 );
	//_DoubleVec[2].push_back( 200 );
	
	size_t number = 0;
	for( ; number < _tempVec.size(); ++number )
	{
	
	}

	cout << _tempVec.size() << endl;
	cout << number << endl;


	return 0;
}
