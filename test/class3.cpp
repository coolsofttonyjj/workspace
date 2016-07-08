/**
 * @file class3.cpp
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
		
		}

		~Base()
		{
		
		}

		void Show()
		{
			cout << "Base::Show1" << endl;
		}

		void Show( int , int )
		{
			cout << "Base::Show2" << endl;
		}
};

class Derived : public Base
{
	public:
		Derived()
		{
		
		}

		~Derived()
		{
		
		}

		using Base::Show;

		void Show( int )
		{
			cout << "Derived::Show" << endl;
		}

		//void Show()
		//{
			//cout << "Derived::Show1" << endl;
		//}
};

int main( int argc, char* argv[] )
{
	Derived d;
	d.Show();
	d.Show(1);
	d.Show(1,1);
	return 0;
}
