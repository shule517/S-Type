#include "StdAfx.h"
#include "BulletFactory.h"
#include "BulletObject.h"

// 各具象
// #include "StandardBullet.h"

/*-------------------------------------------
	コンストラクタ
--------------------------------------------*/
BulletFactory::BulletFactory()
{
}

/*-------------------------------------------
	デストラクタ
--------------------------------------------*/
BulletFactory::~BulletFactory()
{
}

/*-------------------------------------------
	インスタンス生成
--------------------------------------------*/
BulletObject* BulletFactory::Create(const E_OBJECT_TYPE objectType, const long x, const long y, const float dir)
{
	BulletObject *bullet = NULL;

	// TODO 各ケース文でオブジェクト種類に合わせて弾生成
	switch (objectType)
	{
	case OBJECT_BULLET_STANDARD:	// 標準弾
//		bullet = new StandardBullet(x, y, animeNo);
		bullet = new BulletObject(x, y, dir);
		break;
/*
	case OBJECT_BULLET_STANDARD:	// レーザー
//		bullet = new StandardBullet(x, y, animeNo);
		bullet = new BulletObject(x, y, dir);
		break;
*/
	default:						// 標準弾
//		bullet = new StandardBullet(x, y, animeNo);
		bullet = new BulletObject(x, y, dir);
		break;
	}

	return bullet;
}
