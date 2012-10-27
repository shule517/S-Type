#pragma once

#include "IObject.h"

class BulletObject : public IObject
{
public:
	BulletObject();
	virtual ~BulletObject();

	void Init();	// 初期化
	void Move();	// 移動
	void Draw();	// 描画
};
