#include "StdAfx.h"
#include "EnemyObject.h"
#include <DirectXLib.h>
#include <Anime.h>

/*-------------------------------------------
	�R���X�g���N�^
--------------------------------------------*/
EnemyObject::EnemyObject(const long x, const long y, const long animeNo)
:anime(NULL)
{
	posX = x;
	posY = y;
	startAnimeNo = animeNo;
}

/*-------------------------------------------
	�f�X�g���N�^
--------------------------------------------*/
EnemyObject::~EnemyObject()
{
}

void EnemyObject::Hit()
{
	PlaySound("data/se/break.wav", NULL, SND_FILENAME | SND_ASYNC);
	life--;
}
