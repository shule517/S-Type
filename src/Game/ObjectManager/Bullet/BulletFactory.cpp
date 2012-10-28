#include "StdAfx.h"
#include "BulletFactory.h"
#include "BulletObject.h"

// 各具象
#include "BulletStandard.h"
#include "BulletMissile.h"

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
		bullet = new BulletStandard(x, y, dir);
		break;

	case OBJECT_BULLET_MISSILE:		// ミサイル
		bullet = new BulletMissile(x, y, dir);
		break;

	default:						// 標準弾
		bullet = new BulletStandard(x, y, dir);
		break;
	}

	// 初期化
	bullet->Init();

	return bullet;
}
