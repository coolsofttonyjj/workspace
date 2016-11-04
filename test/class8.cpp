/**
 * @file class8.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-10-12
 */

#include <iostream>
using std::cout;
using std::endl;

class Base1
{
	public:
		Base1()
		{
			cout << "This is Base1" << endl;
		}

		~Base1()
		{
			cout << "______This is Base1" << endl;
		}
};

class Base2 : public Base1
{
	public:
		Base2()
		{
			cout << "This is Base2" << endl;
		}

		~Base2()
		{
			cout << "______This is Base2" << endl;
		}
};

class Base3 : public Base2
{
	public:
		Base3()
		{
			cout << "This is Base3" << endl;
		}

		~Base3()
		{
			cout << "______This is Base3" << endl;
		}
};

void haha( const bool& b )
{

}

int main( int argc, char* argv[] )
{
	Base3 m;
	haha(true);
	return 0;
}
