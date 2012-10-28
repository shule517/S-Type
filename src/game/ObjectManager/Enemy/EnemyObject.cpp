#include "StdAfx.h"
#include "EnemyObject.h"
#include <DirectXLib.h>
#include <Anime.h>

/*-------------------------------------------
	コンストラクタ
--------------------------------------------*/
EnemyObject::EnemyObject(const long x, const long y, const long animeNo)
:accelY(1.1f),
gravity(0.4f)
{
	posX = x;
	posY = y;
	startAnimeNo = animeNo;
}

/*-------------------------------------------
	デストラクタ
--------------------------------------------*/
EnemyObject::~EnemyObject()
{
	delete aramakiAnime;
}

/*-------------------------------------------
	初期化
--------------------------------------------*/
void EnemyObject::Init()
{
	aramakiAnime = new Anime("data/aramaki/aramaki.xml");
	aramakiAnime->SetAnime(startAnimeNo);
}

/*-------------------------------------------
	動作
--------------------------------------------*/
void EnemyObject::Move()
{
	accelY += gravity;
	posY += static_cast<long>(accelY);

	if (posY > 500)
	{
		posY = 500;
		aramakiAnime->SetAnime(1);
	}
}

/*-------------------------------------------
	描画
--------------------------------------------*/
void EnemyObject::Draw()
{
	aramakiAnime->Draw(posX, posY);
}
