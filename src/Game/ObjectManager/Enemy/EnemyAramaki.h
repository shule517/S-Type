#pragma once

#include "EnemyObject.h"

class EnemyAramaki : public EnemyObject
{
public:
	EnemyAramaki(const long x, const long y, const long animeNo);
	virtual ~EnemyAramaki();

	void Init();	// 初期化
	void Move();	// 移動
	void Draw();	// 描画

private:
	float accelY;			// 加速度Y
	float gravity;			// 重量
};
