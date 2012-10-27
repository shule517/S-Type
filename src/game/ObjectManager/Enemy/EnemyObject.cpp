#include "StdAfx.h"
#include "EnemyObject.h"
#include <DirectXLib.h>
#include <Anime.h>

/*-------------------------------------------
	コンストラクタ
--------------------------------------------*/
EnemyObject::EnemyObject(long x, long y)
{
	posX = x;
	posY = y;
	accelY = 1.1;
	gravity = 0.4;
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
}

/*-------------------------------------------
	動作
--------------------------------------------*/
void EnemyObject::Move()
{
	accelY += gravity;
	posY += accelY;

	if (posY > 500)
	{
		posY = 500;
		aramakiAnime->setAnime(1);
	}
}

/*-------------------------------------------
	描画
--------------------------------------------*/
void EnemyObject::Draw()
{
	aramakiAnime->Draw(posX, posY);
}
