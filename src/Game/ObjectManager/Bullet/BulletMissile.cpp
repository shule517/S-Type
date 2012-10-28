#include "StdAfx.h"
#include "BulletMissile.h"
#include <DirectXLib.h>
#include <Anime.h>

/*-------------------------------------------
	コンストラクタ
--------------------------------------------*/
BulletMissile::BulletMissile(const long x, const long y, const float dir)
:BulletObject(x, y, dir),
accelY(1.1f),
gravity(1.0f)
{
	// TODO 引数でアニメ番号をもらう必要有り？
	posX = x;
	posY = y;
	startAnimeNo = 0;
	life = 10;
}

/*-------------------------------------------
	デストラクタ
--------------------------------------------*/
BulletMissile::~BulletMissile()
{
	delete anime;
}

/*-------------------------------------------
	初期化
--------------------------------------------*/
void BulletMissile::Init()
{
	anime = new Anime("data/aramaki/aramaki.xml");
	anime->SetAnime(startAnimeNo);
}

/*-------------------------------------------
	動作
--------------------------------------------*/
void BulletMissile::Move()
{
	accelY += gravity;
	posX += accelY;

	/*
	posY += static_cast<long>(accelY);

	if (posY > 500)
	{
		posY = 500;
		anime->SetAnime(1);
	}
	*/
}

/*-------------------------------------------
	描画
--------------------------------------------*/
void BulletMissile::Draw()
{
	D3DXVECTOR2 pos = GetClientPos();
	anime->Draw(pos.x, pos.y);
}
