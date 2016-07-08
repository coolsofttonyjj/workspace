/**
 * @file testnew.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-06-16
 */

#include <iostream>
using std::cout;
using std::endl;

struct Nonumber
{
	Nonumber( int _a, int _b, int _c ) : a(_a), b(_b), c(_c)
	{
		cout << a << endl;
		cout << b << endl;
		cout << c << endl;
	}
	int a;
	int b;
	int c;
};

int main( int argc, char* argv[] )
{
	int *a = new int[10];
	for( int i = 0; i < 10; ++i )
	{
		a[i] = i;
		cout << a[i] << endl;
	}
	delete []a;

	Nonumber* n = new Nonumber(1,2,3);
	delete n;

	int* aa = (int*)operator new(sizeof(int));
	operator delete((void*)aa);

	int* aaa = (int*)operator new[](sizeof(int)*10);
	for( int i = 0; i < 10; ++i )
	{
		aaa[i] = i;
		cout << aaa[i] << endl;
	}
	operator delete[]((void*)aaa);
	
	Nonumber* nn = (Nonumber*)operator new( sizeof(Nonumber) );
	Nonumber* nnn = new(nn) Nonumber(10,20,30);
	operator delete((void*)nn);

	char temp[128];
	Nonumber* nb = new(temp) Nonumber(100,200,300);

	return 0;
}
