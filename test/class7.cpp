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

class Unique
{
	public:
		Unique()
		{
			abc = 0;
		}
		Unique( int a )
		{
			abc = a;
		}

		int Add()
		{
			return ++abc;
		}

		int abc;
};

class Base
{
	public:
		Base()
		{
			cout << "THIS IS base" << endl;
		}

		virtual ~Base()
		{
			cout << "This is Base" <<endl;
		}

		virtual void Show()
		{
		
		}

		void Init();
		void Clear();

		static Unique m_Unique;
		Base* m_Base[2];
};

Unique Base::m_Unique(10);

class A : public Base, public Singleton<A>
{
	public:
		A()
		{
			cout << "THIS IS A" << endl;
		}
		~A()
		{
			cout << "This is A" << endl;
		}

		virtual void Show()
		{
			cout << "AAAAAAAAAAA:" << m_Unique.Add() << endl;
		}
};

class B : public Base, public Singleton<B>
{
	public:
		B()
		{
			cout << "THIS IS B" << endl;
		}
		~B()
		{
			cout << "This is B" << endl;
		}
		virtual void Show()
		{
			cout << "BBBBBBBBBBB:" << m_Unique.Add() <<endl;
		}
};

void Base::Init()
{
	m_Base[0] = NULL;
	m_Base[1] = NULL;
	m_Base[0] = A::Instance();
	m_Base[1] = B::Instance();
}

void Base::Clear()
{
	delete m_Base[0];
	m_Base[0] = NULL;
	delete m_Base[1];
	m_Base[1] = NULL;
}

int main( int artc, char* argv[] )
{
	//Base* p1 = A::Instance();
	//p1->Show();
	//Base* p2 = B::Instance();
	//p2->Show();
	////delete p1;
	////p1 = NULL;
	////delete p2;
	////p2 = NULL;
	//A::DelMe();
	//B::DelMe();
	Base abc;
	abc.Init();
	abc.m_Base[0]->Show();
	abc.m_Base[1]->Show();
	abc.Clear();
	return 0;
}
