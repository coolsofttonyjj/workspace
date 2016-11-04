/**
 * @file test2.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-10-19
 */

#include <iostream>
using std::cout;
using std::endl;

char temp[1024];

struct haha
{
	int size = 0;
	int ar[0];
};

int main( int argc, char* argv[] )
{
	haha* p = new(temp)haha;
	for( int i = 0; i < 10; ++i )
	{
		*((int*)(p->ar)+i) = 100 + i;
	}
	p->size = 10;
	return 0;
}
