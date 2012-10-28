#include "StdAfx.h"
#include "EnemyAramaki.h"
#include <DirectXLib.h>
#include <Anime.h>

/*-------------------------------------------
	コンストラクタ
--------------------------------------------*/
EnemyAramaki::EnemyAramaki(const long x, const long y, const long animeNo)
:EnemyObject(x, y, animeNo),
accelY(1.1f),
gravity(0.4f)
{
	posX = x;
	posY = y;
	startAnimeNo = animeNo;
}

/*-------------------------------------------
	デストラクタ
--------------------------------------------*/
EnemyAramaki::~EnemyAramaki()
{
	delete anime;
}

/*-------------------------------------------
	初期化
--------------------------------------------*/
void EnemyAramaki::Init()
{
	anime = new Anime("data/aramaki/aramaki.xml");
	anime->SetAnime(startAnimeNo);
}

/*-------------------------------------------
	動作
--------------------------------------------*/
void EnemyAramaki::Move()
{
	accelY += gravity;
	posY += static_cast<long>(accelY);

	if (posY > 500)
	{
		posY = 500;
		anime->SetAnime(1);
	}
}

/*-------------------------------------------
	描画
--------------------------------------------*/
void EnemyAramaki::Draw()
{
	D3DXVECTOR2 pos = GetClientPos();
	anime->Draw(pos.x, pos.y);
}
