/**
 * @file class6.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-08-03
 */

#include <iostream>
using std::cout;
using std::endl;

class Scene
{
	public:
		Scene()
		{
		
		}

		~Scene()
		{
		
		}

		virtual void Show()
		{
			cout << "Scene" << endl;
		}
};

class CastleScene : public Scene
{
	public:
		CastleScene()
		{
		
		}

		~CastleScene()
		{
		
		}

		virtual void Show()
		{
			cout << "CastleScene" << endl;
		}

		void Handle()
		{
			cout << "CastleScene's Handle" << endl;
		}

		static void Init()
		{
			cout << "CastleScene's Init" << endl;
		}
};

class MobaScene : public CastleScene
{
	public:
		MobaScene()
		{
		
		}

		~MobaScene()
		{
		
		}

		virtual void Show()
		{
			cout << "MobaScene" << endl;
		}

		void Handle()
		{
			cout << "MobaScene's Handle" << endl;
		}

		static void Init()
		{
			cout << "MobaScene's Init" << endl;
		}
};

int main( int argc, char* argv[] )
{
	Scene* pA = new CastleScene;
	Scene* pB = new MobaScene;
	pA->Show();
	pB->Show();

	CastleScene* _pA = dynamic_cast<CastleScene*>(pA);
	_pA->Handle();
	_pA->Init();
	MobaScene* _pB = dynamic_cast<MobaScene*>(pB);
	_pB->Handle();
	_pB->Init();

	CastleScene::Init();
	MobaScene::Init();

	delete pA;
	pA = NULL;
	delete pB;
	pB = NULL;
	return 0;
}
