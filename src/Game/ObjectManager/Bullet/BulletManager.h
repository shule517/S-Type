#pragma once

#include <list>
#include "../E_OBJECT_TYPE.h"

class BulletFactory;
class BulletObject;

// �e�Ǘ�
class BulletManager
{
public:
	static BulletManager* GetInstance();

	void ShootBullet(E_OBJECT_TYPE objectType, float x, float y, float dir);

	void Init();
	void Move();
	void Draw();

	const list<BulletObject*>& GetObject(){ return bulletList; }

private:
	BulletManager();
	virtual ~BulletManager();

private:
	BulletFactory* bulletFactory;	// �e����
	list<BulletObject*> bulletList;	// �G���X�g
};
