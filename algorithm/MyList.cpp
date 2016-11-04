/**
 * @file MyList.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-08-17
 */

#include <iostream>

using std::cout;
using std::endl;

struct Node
{
	Node()
	{
		m_value = 0;
		m_pNext = 0;
	}
	int m_value;
	Node* m_pNext;
};

class MyList
{
	public:
		MyList()
		{
			m_first = NULL;
			m_end = NULL;
			m_Num = 0;
		}

		~MyList()
		{
		
		}

		int InitList()
		{
			return 0;
		}

		bool Empty()
		{
			return true;
		}

		int Clear()
		{
			return 0;
		}

		int Insert( int _value )
		{
			return 0;
		}

		int Erase( int _value )
		{
			return 0;
		}

		int GetElem( int _pos )
		{
			return 0;
		}

		int LocateElem( int _value )
		{
			return 0;
		}

		int Length()
		{
			return 0;
		}


	protected:


	private:
		Node* m_first;
		Node* m_end;
		int m_Num;
};

int main( int argc, char* argv[] )
{
	return 0;
}
