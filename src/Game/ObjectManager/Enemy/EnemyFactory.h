#pragma once

#include "../E_OBJECT_TYPE.h"

class EnemyObject;
// ìGê∂ê¨
class EnemyFactory
{
public:
	EnemyFactory();
	virtual ~EnemyFactory();

	EnemyObject* Create(const E_OBJECT_TYPE objectType, const long x, const long y, const long animeNo);
};
