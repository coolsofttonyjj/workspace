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

using namespace std;

int main( int argc, char* argv[] )
{
	float total = 0;
	int num = 100;
	total = ( num / 90 + 100 ) / 100.0f;
	cout << total << endl;

	int buffer[0];
	cout << sizeof( buffer ) << endl;

	char buffer1[3][3][3];
	bzero( buffer1, sizeof(buffer1) );
	buffer1[0][0][0] = 'a';
	buffer1[0][0][1] = 'b';
	buffer1[0][0][2] = 'c';
	buffer1[0][1][0] = 'd';
	buffer1[0][1][1] = 'e';
	buffer1[0][1][2] = 'f';
	buffer1[0][2][0] = 'g';
	buffer1[0][2][1] = 'h';
	buffer1[0][2][2] = 'i';
	buffer1[1][0][0] = 'j';
	buffer1[1][0][1] = 'k';
	buffer1[1][0][2] = 'l';
	buffer1[1][1][0] = 'm';
	buffer1[1][1][1] = 'n';
	buffer1[1][1][2] = 'o';
	buffer1[1][2][0] = 'p';
	buffer1[1][2][1] = 'q';
	buffer1[1][2][2] = 'r';
	buffer1[2][0][0] = 's';
	buffer1[2][0][1] = 't';
	buffer1[2][0][2] = 'u';
	buffer1[2][1][0] = 'v';
	buffer1[2][1][1] = 'w';
	buffer1[2][1][2] = 'x';
	buffer1[2][2][0] = 'y';
	buffer1[2][2][1] = 'z';
	buffer1[2][2][2] = '0';
	cout << sizeof( buffer1 ) << endl;

	auto& temp1 = buffer1[1][1];
	auto& temp2 = buffer1[1];

	for( int i = 0 ; i < 10000; ++i )
	{
		if( i % 1 == 0 && i % 2 == 1 &&
			i % 3 == 0 && i % 4 == 1 &&
			i % 5 == 4 && i % 6 == 3 &&
			i % 7 == 5 && i % 8 == 1 && i % 9 == 0) 
		{
			cout << i << endl;
		}
	}

	return 0;
}
