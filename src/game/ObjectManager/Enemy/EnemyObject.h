#pragma once

#include "../IObject.h"

class EnemyObject : public IObject
{
public:
	EnemyObject();
	virtual ~EnemyObject();

	void Init();	// 初期化
	void Move();	// 移動
	void Draw();	// 描画
};
