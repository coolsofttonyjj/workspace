/**
 * @file class7.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-10-09
 */

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class SingletonFactory
{
	public:
		static T* Create()
		{
			return new T();
		}
};

template <typename T, typename MANA = SingletonFactory<T> >
class Singleton
{
	private:
		//禁用 拷贝构造函数
		Singleton( const Singleton& );
		//禁用 赋值操作符号
		const Singleton& operator=( const Singleton& );

	protected:
		static T* ms_Singleton;
		Singleton()
		{
			if( !ms_Singleton )
			{
				ms_Singleton = static_cast<T*>(this);
			}
		}

		~Singleton()
		{
			ms_Singleton = NULL;
		}

	public:
		static void DelMe()
		{
			if( ms_Singleton )
			{
				delete ms_Singleton;
				ms_Singleton = NULL;
			}
		}

		static T* Instance()
		{
			if( !ms_Singleton )
			{
				MANA::Create();
			}

			return ms_Singleton;
		}

		static T& GetMe()
		{
			if( !ms_Singleton )
			{
				MANA::Create();
			}
			return *ms_Singleton;
		}
};

template< typename T, typename MANA >
T* Singleton<T,MANA>::ms_Singleton = NULL;

class Base
{
	public:
		Base()
		{
		
		}

		virtual ~Base()
		{
			cout << "This is Base" <<endl;
		}

		virtual void Show() = 0;
};

class A : public Base, public Singleton<A>
{
	public:
		~A()
		{
			cout << "This is A" << endl;
		}

		virtual void Show()
		{
			cout << "AAAAAAAAAAA" << endl;
		}
};

class B : public Base, public Singleton<B>
{
	public:
		~B()
		{
			cout << "This is B" << endl;
		}
		virtual void Show()
		{
			cout << "BBBBBBBBBBB" << endl;
		}
};

int main( int artc, char* argv[] )
{
	Base* p1 = A::Instance();
	p1->Show();
	Base* p2 = B::Instance();
	p2->Show();
	//delete p1;
	//p1 = NULL;
	//delete p2;
	//p2 = NULL;
	A::DelMe();
	B::DelMe();
	return 0;
}
