#pragma once

#include "BulletObject.h"

class BulletStandard : public BulletObject
{
public:
	BulletStandard(const long x, const long y, const float dir);
	virtual ~BulletStandard();

	void Init();	// ‰Šú‰»
	void Move();	// ˆÚ“®
	void Draw();	// •`‰æ

private:
	float accelY;			// ‰Á‘¬“xY
	float gravity;			// d—Ê
};
