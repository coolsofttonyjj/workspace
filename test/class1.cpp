/**
 * @file class1.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-04-13
 */

#include <iostream>
using namespace std;

class A
{
	public:
		A()
		{
			cout << "This is A" << endl;
		}
		~A()
		{
			cout << "destory A" << endl;
		}

		void show()
		{
			cout << "Show A" << endl;
		}
};

class B : virtual public A
{
	public:
		B()
		{
			cout << "This is B" << endl;
		}
		~B()
		{
			cout << "destory B" << endl;
		}
};

class C : virtual public A
{
	public:
		C()
		{
			cout << "This is C" << endl;
		}
		~C()
		{
			cout << "destory C" << endl;
		}
};

class D : virtual public A
{
	public:
		D()
		{
			cout << "This is D" << endl;
		}
		~D()
		{
			cout << "destory D" << endl;
		}
};

class E : public B, public C, public D
{
	public:
		E()
		{
			cout << "This is E" << endl;
		}
		~E()
		{
			cout << "destory E" << endl;
		}
};

class AA
{
	public:
		AA()
		{}
		~AA()
		{}

		int a;
};

class BB
{
	public:
		BB()
		{
		
		}

		~BB()
		{
		
		}

		void ShowBB()
		{
			cout << "bb" << endl;
		}
};

int main( int argc, char* argv[] ) 
{
	cout << sizeof( A ) << endl;
	cout << sizeof( B ) << endl;
	cout << sizeof( C ) << endl;
	cout << sizeof( D ) << endl;
	cout << sizeof( E ) << endl;
	cout << sizeof( AA ) << endl;
	E d;
	d.show();
	BB bb;
	bb.ShowBB();
	return 0;
}
