#pragma once

#include "../IObject.h"

class Anime;
class EnemyObject : public IObject
{
public:
	EnemyObject(const long x, const long y, const long animeNo);
	virtual ~EnemyObject();

	// 以下は、各具象クラスで実装する
	// void Init();	// 初期化
	// void Move();	// 移動
	// void Draw();	// 描画

protected:
	Anime *anime;	// アニメ
};
