#pragma once

#include "../IObject.h"

class BulletObject : public IObject
{
public:
	BulletObject(const long x, const long y, const float dir);
	virtual ~BulletObject();

	void Init();	// 初期化
	void Move();	// 移動
	void Draw();	// 描画

private:
	float bulletDir;	// 弾方向
};
