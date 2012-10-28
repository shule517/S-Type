#pragma once

#include "EnemyObject.h"

class EnemyShobonTower : public EnemyObject
{
public:
	EnemyShobonTower(const long x, const long y, const long animeNo);
	virtual ~EnemyShobonTower();

	void Init();	// ‰Šú‰»
	void Move();	// ˆÚ“®
	void Draw();	// •`‰æ

private:
	float accelY;			// ‰Á‘¬“xY
	float gravity;			// d—Ê
};
