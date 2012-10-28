#include "StdAfx.h"
#include "EnemyAramaki.h"
#include <DirectXLib.h>
#include <Anime.h>
#include "../Boon/Boon.h"

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
	life = 5;
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
	static bool isDown = false;

	// X軸が近いと落ちる
	long boonX = Boon::GetInstance()->posX;
	if (((posX - 10) < boonX) && (boonX  < (posX + 10)))
	{
		isDown = true;
	}

	if (isDown)
	{
		accelY += gravity;
		posY += static_cast<long>(accelY);
	}

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
