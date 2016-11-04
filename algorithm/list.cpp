/**
 * @file list.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-08-05
 */

#include <iostream>
#include <list>
using std::cout;
using std::endl;

int main( int argc, char* argv[] )
{
	std::list<int> _list;
	for( int i = 1; i < 10; ++i )
	{
		_list.push_back( i * 10 );
	}

	//auto it = _list.begin();
	//while( it != _list.end() )
	//{
		//if( (*it) < 5 )
		//{
			//it = _list.erase( it );
		//}
		//else
		//{
			//break;
		//}
	//}

	//auto iter = _list.begin();
	//while( iter != _list.end() )
	//{
		//cout << *iter << endl;
		//++iter;
	//}

	int abc = 11;
	if( !_list.empty() )
	{
		if( abc <= _list.front() )
		{
			_list.push_front( abc );
		}
		else if( abc >= _list.back() )
		{
			_list.push_back( abc );
		}
		else
		{
			auto it = _list.begin();
			auto itend = _list.end();
			while( it != itend )
			{
				if( *it > abc )
				{
					_list.insert( it, abc );
					break;
				}
				++it;
			}
		}
	}

	auto iter = _list.begin();
	while( iter != _list.end() )
	{
		cout << *iter << endl;
		++iter;
	}

	return 0;
}
