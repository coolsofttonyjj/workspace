/**
 * @file ScreenIndex.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2017-03-07
 */

#include <iostream>
#include <vector>
#include <map>
using std::cout;
using std::endl;

typedef unsigned int		DWORD;

class MapIndex
{
	public:
		MapIndex( int _x, int _y ) : m_X( _x ), m_Y( _y ), m_Total( _x * _y )
		{
		
		}
		~MapIndex()
		{
		
		}

		bool Init()
		{
			const int adjust[9][2] = {  { 0, -1 },
									    { 1, -1 },
										{ 1, 0 },
										{ 1, 1 },
										{ 0, 1 },
										{ -1, 1 },
										{ -1, 0 },
										{ -1, -1 },
										{ 0, 0 }
								  	 };

			for( DWORD index = 0; index < m_Total; ++index )
			{
				int tempX = index % m_X;
				int tempY = index / m_X;
				{
					//计算周围九屏
					std::vector<DWORD> _vec;
					for( int i = 0; i < 9; ++i )
					{
						int x = tempX + adjust[i][0];
						int y = tempY + adjust[i][1];
						if( x >=0 && y >= 0 && x < (int)m_X && y < (int)m_Y )
						{
							_vec.push_back( y * m_X + x );
						}
					}
					m_NineScreen[index] = _vec;
				}

				//计算正向变化五屏或者三屏
				for( int dir = 0; dir < 8; ++dir )
				{
					int start = 0;
					int end = 0;
					std::vector< DWORD > _vec;
					if( dir % 2 == 1 )
					{
						//斜方向
						start = 6;
						end = 10;
					}
					else
					{
						//正方向
						start = 7;
						end = 9;
					}

					for( int i = start; i <= end; ++i )
					{
						int x = tempX + adjust[ ( i + dir ) % 8 ][0];
						int y = tempY + adjust[ ( i + dir ) % 8 ][1];
						if( x >= 0 && y >= 0 && x < (int)m_X && y < (int)m_Y )
						{
							_vec.push_back( y * m_X + x );
						}
					}
					m_DirectScreen[dir].insert( NineScreenMap::value_type( index, _vec ) );
				}

				//计算反向变化五屏或者三屏
				for( int dir = 0; dir < 8; ++dir )
				{
					int start = 0;
					int end = 0;
					std::vector< DWORD > _vec;
					if( dir % 2 == 1 )
					{
						//斜方向
						start = 2;
						end = 6;
					}
					else
					{
						//正方向
						start = 3;
						end = 5;
					}

					for( int i = start; i <= end; ++i )
					{
						int x = tempX + adjust[ ( i + dir ) % 8 ][0];
						int y = tempY + adjust[ ( i + dir ) % 8 ][1];
						if( x >=0 && y >= 0 && x < (int)m_X && y < (int)m_Y )
						{
							_vec.push_back( y * m_X + x );
						}
					}
					m_ReverseDirectScreen[dir].insert( NineScreenMap::value_type( index, _vec ) );
				}
			}

			m_NineScreen.insert( std::make_pair( (DWORD)-1, std::vector<DWORD>() ) );
			for( int dir = 0; dir < 8; ++dir )
			{
				m_DirectScreen[dir].insert( std::make_pair( (DWORD)-1, std::vector<DWORD>() ) );
				m_ReverseDirectScreen[dir].insert( std::make_pair( (DWORD)-1, std::vector<DWORD>() ) );
			}
			return true;
		}

		const std::vector<DWORD>& GetNineScreen( const DWORD& _index )
		{
			auto iter = m_NineScreen.find( _index );
			if( iter != m_NineScreen.end() )
			{
				cout << "当前格子: " << _index << endl;
				for( auto& value : iter->second )
				{
				
					cout << "当前格子的九屏: " << value << endl;
				}
				return iter->second;
			}

			return m_NineScreen.find( (DWORD)-1)->second;
		}

		const std::vector<DWORD>& GetDirectScreen( const DWORD& _index, const DWORD& _dir )
		{
			auto iter = m_DirectScreen[_dir].find( _index );
			if( iter != m_DirectScreen[_dir].end() )
			{
				cout << "当前格子: " << _index << endl;
				for( auto& value : iter->second )
				{
				
					cout << "当前格子的九屏: " << value << endl;
				}
				cout << "=====================================" << endl;
				return iter->second;
			}

			return m_NineScreen.find( (DWORD)-1)->second;
		}

		const std::vector<DWORD>& GetReverseDirectScreen( const DWORD& _index, const DWORD& _dir )
		{
			auto iter = m_ReverseDirectScreen[_dir].find( _index );
			if( iter != m_ReverseDirectScreen[_dir].end() )
			{
				cout << "当前格子: " << _index << endl;
				for( auto& value : iter->second )
				{
				
					cout << "当前格子的九屏: " << value << endl;
				}
				cout << "=====================================" << endl;
				return iter->second;
			}

			return m_NineScreen.find( (DWORD)-1)->second;
		}

	private:

		typedef std::map< DWORD, std::vector< DWORD > > NineScreenMap;
		DWORD m_X;
		DWORD m_Y;
		DWORD m_Total;

		NineScreenMap m_NineScreen;
		NineScreenMap m_DirectScreen[8];
		NineScreenMap m_ReverseDirectScreen[8];
};


int main( int artc, char* argv[] )
{
	MapIndex _temp( 10, 5 );
	_temp.Init();
	//_temp.GetNineScreen( 24 );
	_temp.GetDirectScreen( 24 , 0 );
	_temp.GetReverseDirectScreen( 24 , 0 );
	return 0;
}
