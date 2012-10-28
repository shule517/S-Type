#pragma once

#include <list>
#include "../E_OBJECT_TYPE.h"

class BulletFactory;
class BulletObject;

// íeä«óù
class BulletManager
{
public:
	BulletManager* GetInstance();

	void ShootBullet(E_OBJECT_TYPE objectType, float x, float y, float dir);

	void Init();
	void Move();
	void Draw();

private:
	BulletManager();
	virtual ~BulletManager();

private:
	BulletFactory* bulletFactory;	// íeê∂ê¨
	list<BulletObject*> bulletList;	// ìGÉäÉXÉg
};
