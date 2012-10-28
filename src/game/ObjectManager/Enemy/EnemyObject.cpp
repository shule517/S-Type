#include "StdAfx.h"
#include "EnemyObject.h"
#include <DirectXLib.h>
#include <Anime.h>

/*-------------------------------------------
	コンストラクタ
--------------------------------------------*/
EnemyObject::EnemyObject(const long x, const long y, const long animeNo)
:anime(NULL)
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
}
