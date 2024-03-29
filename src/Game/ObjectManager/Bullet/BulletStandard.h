#pragma once

#include "BulletObject.h"

class BulletStandard : public BulletObject
{
public:
	BulletStandard(const long x, const long y, const float dir);
	virtual ~BulletStandard();

	void Init();	// 初期化
	void Move();	// 移動
	void Draw();	// 描画

private:
	float accelY;			// 加速度Y
	float gravity;			// 重量
};
