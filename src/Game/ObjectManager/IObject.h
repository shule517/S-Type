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
	boundsHeight(0),
	startAnimeNo(0)
	{};
	virtual ~IObject(){};

	virtual void Init()= 0;	// 初期化
	virtual void Move()= 0;	// 移動
	virtual void Draw()= 0;	// 描画
// TODO	virtual void Hit()=0;	// ぶつかった


	/*-------------------------------------------
	オブジェクト同士の当たり判定
	objectA / objectBの当たり判定チェック
	--------------------------------------------*/
// TODO bool IsHit(const IObject& a, const IObject& b)
	bool IsHit(const IObject& a, const IObject& b)
	{
		long ax1 = a.posX + (a.imageWidth  - a.boundsWidth) / 2;
		long ay1 = a.posY + (a.imageHeight - a.imageHeight) / 2;
		long ax2 = a.posX + (a.imageWidth  - a.boundsWidth) / 2;
		long ay2 = a.posY + (a.imageHeight - a.imageHeight) / 2;
		long bx1 = b.posX + (b.imageWidth  - a.boundsWidth) / 2;
		long by1 = b.posY + (b.imageHeight - a.imageHeight) / 2;
		long bx2 = b.posX + (b.imageWidth  - a.boundsWidth) / 2;
		long by2 = b.posY + (b.imageHeight - a.imageHeight) / 2;
		
		if ((ax1 < bx2) &&
			(bx1 < ax2) &&
			(ay1 < by2) &&
			(by1 < ay2))
		{
			return true;
		}
		
		return false;
	}

protected:
	long posX;				// X座標
	long posY;				// Y座標
	long imageWidth;		// 画像幅
	long imageHeight;		// 画像高さ
	long boundsWidth;		// 当たり判定(幅)
	long boundsHeight;		// 当たり判定(高さ)
	long startAnimeNo;		// 開始アニメNo
};
