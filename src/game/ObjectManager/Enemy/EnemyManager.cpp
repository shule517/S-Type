#include "StdAfx.h"
#include "EnemyManager.h"
#include "EnemyObject.h"

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
:enemyList()
{
}

/*-------------------------------------------
	デストラクタ
--------------------------------------------*/
EnemyManager::~EnemyManager()
{
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
void EnemyManager::AddEnemy(EnemyObject* enemy)
{
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
