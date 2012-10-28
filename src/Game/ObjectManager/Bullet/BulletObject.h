#pragma once

#include "../IObject.h"

class BulletObject : public IObject
{
public:
	BulletObject(const long x, const long y, const float dir);
	virtual ~BulletObject();

	void Init();	// ‰Šú‰»
	void Move();	// ˆÚ“®
	void Draw();	// •`‰æ

private:
	float bulletDir;	// ’e•ûŒü
};
