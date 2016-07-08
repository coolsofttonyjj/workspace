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
#include <queue>
#include <deque>
#include <map>
#include <vector>
using namespace std;

union DataUnion
{
	unsigned short _id;
	struct
	{
		unsigned char cmd;
		unsigned char para;
	};
};

struct DataStruct
{
	union
	{
		unsigned char _id;
		struct
		{
			unsigned char _a:1;	
			unsigned char _b:1;	
			unsigned char _c:1;	
			unsigned char _d:1;	
			unsigned char _e:1;	
			unsigned char _f:1;	
			unsigned char _g:1;	
			unsigned char _h:1;	
		};
	};

	DataUnion abc;
};

int GetInt()
{
	return -1;
}

#define XXXX(x) AA##x
#define AAAA( sec, sym )	"___ksymtab" sec "+" #sym
#define BBBB( exp ) \
	__extension__	\
	( exp )

int main( int argc, char* argv[] )
{
	DataUnion d;
	d.cmd = 222;
	d.para = 7;
	cout << d._id << endl;
	d._id = 770;
	cout << (int)d.cmd << endl;
	cout << (int)d.para << endl;

	//DataStruct dd;
	//dd.abc._id = 255;
	//dd._id = 3;
	//cout << (int)dd._a << endl;
	//cout << (int)dd._b << endl;
	//
	//int AA1 = 10;
	cout << AAAA( "", tcp ) << endl;
	cout << BBBB(GetInt()) << endl;

	std::queue< int , std::deque<int> > _queue;
	for( int i = 0; i < 10; ++i )
	{
		_queue.push( i );
	}

	while( !_queue.empty() )
	{
		cout << _queue.front() << endl;
		_queue.pop();
	}

	std::map< int, std::vector<int> > _map;
	_map[1] = std::vector<int>();
	int data[] = {11,22,33,44};
	_map[1] = std::vector<int>( data, data + sizeof(data)/sizeof(int) );
	auto it = _map.find(1);
	for( size_t i = 0 ; i < it->second.size(); ++i )
	{
		cout << it->second[i] << endl;
	}

	return 0;
}

