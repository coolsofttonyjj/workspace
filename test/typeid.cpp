/**
 * @file typeid.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-04-29
 */

#include <iostream>
#include <typeinfo>
using std::cout;
using std::endl;

class Base
{
	public:
		Base(){}
		~Base(){}
};

struct Sase
{
	public:
		Sase(){}
		~Sase(){}
};

int main( int argc, char* argv[] )
{
	char a;
	Base b;
	Sase c;
	Base* p = NULL;
	int* pInt = NULL;
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(p).name() << endl;
	cout << typeid(pInt).name() << endl;
	return 0;
}
