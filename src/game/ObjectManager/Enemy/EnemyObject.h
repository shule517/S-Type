#pragma once

#include "../IObject.h"

class Anime;
class EnemyObject : public IObject
{
public:
	EnemyObject(long x, long y);
	virtual ~EnemyObject();

	void Init();	// 初期化
	void Move();	// 移動
	void Draw();	// 描画

private:
	Anime *aramakiAnime;	// アニメ
	float accelY;			// 加速度Y
	float gravity;			// 重量
};
