#pragma once

#include "Stage/StageManager.h"

class IObject
{
public:
	IObject()
	:posX(0),
	posY(0),
	imageWidth(32),		// TODO XMLからデータ取得する
	imageHeight(32),	// TODO XMLからデータ取得する 
	boundsWidth(32),	// TODO XMLからデータ取得する
	boundsHeight(32),	// TODO XMLからデータ取得する
	startAnimeNo(0),	// TODO XMLからデータ取得する
	life(1)				// TODO XMLからデータ取得する
	{};
	virtual ~IObject(){};

	virtual void Init()= 0;	// 初期化
	virtual void Move()= 0;	// 移動
	virtual void Draw()= 0;	// 描画
	virtual void Hit(){};	// ぶつかった

	// 表示位置を取得
	D3DXVECTOR2 GetClientPos()
	{
		// ステージ座標を取得
		D3DXVECTOR2 stagePos = StageManager::GetInstance()->GetStagePos();

		// 表示位置(Client座標)を返す
		return D3DXVECTOR2(posX - stagePos.x, posY - stagePos.y);
	}

// 本来は「protected」
	long posX;				// X座標
	long posY;				// Y座標
	long imageWidth;		// 画像幅
	long imageHeight;		// 画像高さ
	long boundsWidth;		// 当たり判定(幅)
	long boundsHeight;		// 当たり判定(高さ)
	long startAnimeNo;		// 開始アニメNo
	long life;				// ライフ
};
