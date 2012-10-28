#pragma once

#include "../IObject.h"

class Anime;

// 弾オブジェクト
class BulletObject : public IObject
{
public:
	BulletObject(const long x, const long y, const float dir);
	virtual ~BulletObject();

	// 以下は、各具象クラスで実装する
	// void Init();	// 初期化
	// void Move();	// 移動
	// void Draw();	// 描画
	void Hit(){ life--; };

protected:
	Anime *anime;		// 弾アニメ
	float bulletDir;	// 弾方向
};
