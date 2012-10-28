#pragma once

#include "BulletObject.h"

class BulletMissile : public BulletObject
{
public:
	BulletMissile(const long x, const long y, const float dir);
	virtual ~BulletMissile();

	void Init();	// ‰Šú‰»
	void Move();	// ˆÚ“®
	void Draw();	// •`‰æ

private:
	float accelY;			// ‰Á‘¬“xY
	float gravity;			// d—Ê
};
