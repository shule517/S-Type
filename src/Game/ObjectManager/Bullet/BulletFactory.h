#pragma once

#include "../E_OBJECT_TYPE.h"

class BulletObject;

// ìGê∂ê¨
class BulletFactory
{
public:
	BulletFactory();
	virtual ~BulletFactory();

	// íeê∂ê¨
	BulletObject* Create(const E_OBJECT_TYPE objectType, const long x, const long y, const float dir);
};
