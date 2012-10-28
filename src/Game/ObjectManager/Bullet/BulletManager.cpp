#include "StdAfx.h"
#include "BulletManager.h"
#include "BulletFactory.h"
#include "BulletObject.h"

/*-------------------------------------------
	インスタンス取得
--------------------------------------------*/
BulletManager* BulletManager::GetInstance()
{
	static BulletManager instance;
	return &instance;
}

/*-------------------------------------------
	コンストラクタ
--------------------------------------------*/
BulletManager::BulletManager()
:bulletList(),
bulletFactory(new BulletFactory())
{
}

/*-------------------------------------------
	デストラクタ
--------------------------------------------*/
BulletManager::~BulletManager()
{
	delete bulletFactory;

	// メモリ解放
	for (std::list<BulletObject*>::iterator it = bulletList.begin(); it != bulletList.end(); ++it)
	{
		delete (*it);
	}
	bulletList.clear();
}

/*-------------------------------------------
	弾を撃つ（弾を追加）
--------------------------------------------*/
void BulletManager::ShootBullet(E_OBJECT_TYPE objectType, float x, float y, float dir)
{
	// ファクトリーで敵生成
	BulletObject *bullet = bulletFactory->Create(objectType, x, y, dir);
	bulletList.push_back(bullet);
}

/*-------------------------------------------
	初期化
--------------------------------------------*/
void BulletManager::Init()
{
	for (std::list<BulletObject*>::iterator it = bulletList.begin(); it != bulletList.end(); ++it)
	{
		(*it)->Init();
	}
}

/*-------------------------------------------
	敵動作
--------------------------------------------*/
void BulletManager::Move()
{
	for (std::list<BulletObject*>::iterator it = bulletList.begin(); it != bulletList.end(); ++it)
	{
		(*it)->Move();
	}
}

/*-------------------------------------------
	敵描画
--------------------------------------------*/
void BulletManager::Draw()
{
	for (std::list<BulletObject*>::iterator it = bulletList.begin(); it != bulletList.end(); ++it)
	{
		(*it)->Draw();
	}
}
