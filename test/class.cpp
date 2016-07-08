/**
 * @file class.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-04-13
 */

#include <iostream>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

#pragma pack(1)

class A
{
	public:
		A()
		{
			cout << "This is A" << endl;
		}

		virtual ~A()
		{
			cout << "Destroy A" << endl;
		}

		virtual void show()
		{
			cout << "This is show A" << endl;
		}
};

class B : public A
{
	public:
		B()
		{
			cout << "This is B" << endl;
		}

		virtual ~B()
		{
			cout << "Destroy B" << endl;
		}

		virtual void show()
		{
			cout << "This is show B" << endl;
		}
};

class C : public B
{
	public:
		C()
		{
			cout << "This is C" << endl;
		}

		virtual ~C()
		{
			cout << "Destroy C" << endl;
		}

		virtual void show()
		{
			cout << "This is show C" << endl;
			a = 10;
		}
		int a;
		int b;
		int c;

};

class D
{
	public:
		D()
		{
			a = 100;
		}

		~D()
		{
		
		}

		operator int()
		{
			return a;
		}

		int a;
};

int main( int argc, char* argv[] )
{
	cout << sizeof( A ) << endl;
	cout << sizeof( B ) << endl;
	cout << sizeof( C ) << endl;
	cout << sizeof( D ) << endl;
	cout << sizeof( char* ) << endl;
	//cout << (long)&((C*)NULL)->a << endl;
	//cout << (long)&((C*)NULL)->b << endl;
	//cout << (long)&((C*)NULL)->c << endl;
	printf("offsets: a=%ld; b=%ld; c=%ld\n",
		( __extension__ (long) offsetof(struct C, a) ),
		(long) offsetof(struct C, b),
		(long) offsetof(struct C, c) );
	A* p = new C;
	p->show();
	delete p;
	p = NULL;


	D* d = new D;
	delete d;
	d = NULL;

	D dd;
	int _d = dd;

	int a[10];
	vector<int> vec;
	map<int, int> _map;
	for( int i = 0; i < 10; ++i )
	{
		a[i] = i;
		vec.push_back(i);
		_map[i] = i * 10;
	}

	vector<int> _vec;
	_vec.push_back(1);
	return 0;
}

