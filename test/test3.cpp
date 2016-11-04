/**
 * @file test3.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-11-04
 */

#include <iostream>
using std::cout;
using std::endl;

struct Base
{
	int type = 1;
};

struct A : public Base
{
	int a = 0;
};

struct B : public Base
{
	int a = 10;
	int b = 100;
};

void show( Base& _b, int type )
{
	if( type == 1 )
	{
		A& a =  static_cast<A&>(_b);
		cout << a.a << endl;
	}
	else if( type == 2 )
	{
		B& b = static_cast<B&>(_b);
		cout << b.a << endl;
		cout << b.b << endl;
	}
}

int Send( int maptype, Base& _base )
{

}

int main( int argc, char* argv[] )
{
	A a;
	a.a = 88;
	B b;

	show( a, 1 );
	show(b, 2);

	return 0;
}

