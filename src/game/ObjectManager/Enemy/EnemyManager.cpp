#include "StdAfx.h"
#include "EnemyManager.h"
#include "EnemyObject.h"
#include "EnemyFactory.h"

/*-------------------------------------------
	インスタンス取得
--------------------------------------------*/
EnemyManager* EnemyManager::GetInstance()
{
	static EnemyManager instance;
	return &instance;
}

/*-------------------------------------------
	コンストラクタ
--------------------------------------------*/
EnemyManager::EnemyManager()
:enemyList(),
enemyFactory(new EnemyFactory())
{
}

/*-------------------------------------------
	デストラクタ
--------------------------------------------*/
EnemyManager::~EnemyManager()
{
	delete enemyFactory;

	// メモリ解放
	for (std::list<EnemyObject*>::iterator it = enemyList.begin(); it != enemyList.end(); ++it)
	{
		delete (*it);
	}
	enemyList.clear();
}

/*-------------------------------------------
	敵追加
--------------------------------------------*/
void EnemyManager::AddEnemy(const E_OBJECT_TYPE objectType, const long x, const long y, const long animeNo)
{
	// ファクトリーで敵生成
	EnemyObject *enemy = enemyFactory->Create(objectType, x, y, animeNo);
	enemyList.push_back(enemy);
}

/*-------------------------------------------
	初期化
--------------------------------------------*/
void EnemyManager::Init()
{
	for (std::list<EnemyObject*>::iterator it = enemyList.begin(); it != enemyList.end(); ++it)
	{
		(*it)->Init();
	}
}

/*-------------------------------------------
	敵動作
--------------------------------------------*/
void EnemyManager::Move()
{
	for (std::list<EnemyObject*>::iterator it = enemyList.begin(); it != enemyList.end(); ++it)
	{
		(*it)->Move();
	}
}

/*-------------------------------------------
	敵描画
--------------------------------------------*/
void EnemyManager::Draw()
{
	for (std::list<EnemyObject*>::iterator it = enemyList.begin(); it != enemyList.end(); ++it)
	{
		(*it)->Draw();
	}
}
