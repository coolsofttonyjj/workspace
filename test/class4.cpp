/**
 * @file class4.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-04-26
 */

#include <iostream>

class User;

class Mail
{
	public:
		Mail( User* p )
		{
		
		}

		~Mail()
		{
		
		}
		int a;
};

class Relation
{
	public:
		Relation( User* p )
		{
		
		}

		~Relation()
		{
		
		}
		int a;
		int b;
};

class Team
{
	public:
		Team( User* p )
		{
		
		}

		~Team()
		{
		
		}
		int a;
		int b;
		int c;
};

class User
{
	public:
		User() : m_Mail( this ), m_Team( this ), m_Relation( this )
		{
		
		}

		~User()
		{
		
		}

		Mail m_Mail;
		Team m_Team;
		Relation m_Relation;
};

int main( int argc, char* argv[] )
{
	User m;
	return 0;
}
