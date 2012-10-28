#pragma once

#include "../E_OBJECT_TYPE.h"

class BulletObject;

// �G����
class BulletFactory
{
public:
	BulletFactory();
	virtual ~BulletFactory();

	// �e����
	BulletObject* Create(const E_OBJECT_TYPE objectType, const long x, const long y, const float dir);
};
