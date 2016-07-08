/**
 * @file class2.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-04-26
 */

#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		Base()
		{
			n = 100;
		}

		~Base()
		{
		
		}

		int GetSize()
		{
			return n;
		}

	protected:
		int n;
};

class Derived : protected Base
{
	public:
		Derived()
		{
		
		}

		~Derived()
		{
		
		}

		using Base::GetSize;
		using Base::n;
};

int main( int argc, char* argv[] )
{
	Derived d;
	d.n = 1000;
	cout << d.GetSize() << endl;
	return 0;
}
