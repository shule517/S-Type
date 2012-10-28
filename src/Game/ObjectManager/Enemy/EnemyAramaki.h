#pragma once

#include "EnemyObject.h"

class EnemyAramaki : public EnemyObject
{
public:
	EnemyAramaki(const long x, const long y, const long animeNo);
	virtual ~EnemyAramaki();

	void Init();	// ‰Šú‰»
	void Move();	// ˆÚ“®
	void Draw();	// •`‰æ

private:
	float accelY;			// ‰Á‘¬“xY
	float gravity;			// d—Ê
};
