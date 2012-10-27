#pragma once

class IObject
{
public:
	IObject()
	:posX(0),
	posY(0),
	imageWidth(0),
	imageHeight(0),
	boundsWidth(0),
	boundsHeight(0)
	{};
	virtual ~IObject(){};

	virtual void Init()= 0;	// 初期化
	virtual void Move()= 0;	// 移動
	virtual void Draw()= 0;	// 描画

protected:
	long posX;				// X座標
	long posY;				// Y座標
	long imageWidth;		// 画像幅
	long imageHeight;		// 画像高さ
	long boundsWidth;		// 当たり判定(幅)
	long boundsHeight;		// 当たり判定(高さ)
};
