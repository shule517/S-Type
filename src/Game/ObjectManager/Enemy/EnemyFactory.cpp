#include "StdAfx.h"
#include "EnemyFactory.h"
#include "EnemyObject.h"

EnemyFactory::EnemyFactory()
{
}

EnemyFactory::~EnemyFactory()
{
}

EnemyObject* EnemyFactory::Create(const E_OBJECT_TYPE objectType, const long x, const long y, const long animeNo)
{
	EnemyObject *enemy = NULL;

	// TODO 各ケース文でオブジェクト種類に合わせて敵生成
	switch (objectType)
	{
	case OBJECT_ARAMAKI:	// 荒巻
		enemy = new EnemyObject(x, y, animeNo);
		break;
	case OBJECT_SHOBON:		// ショボンタワー
		enemy = new EnemyObject(x, y, animeNo);
		break;
	default:
		enemy = new EnemyObject(x, y, animeNo);
		break;
	}

	return enemy;
}
