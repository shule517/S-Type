#pragma once

#include "BulletObject.h"

class BulletMissile : public BulletObject
{
public:
	BulletMissile(const long x, const long y, const float dir);
	virtual ~BulletMissile();

	void Init();	// 初期化
	void Move();	// 移動
	void Draw();	// 描画

private:
	float accelY;			// 加速度Y
	float gravity;			// 重量
};
