#include "StdAfx.h"
#include "EnemyObject.h"
#include <DirectXLib.h>
#include <Anime.h>

/*-------------------------------------------
	�R���X�g���N�^
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
	�f�X�g���N�^
--------------------------------------------*/
EnemyObject::~EnemyObject()
{
	delete aramakiAnime;
}

/*-------------------------------------------
	������
--------------------------------------------*/
void EnemyObject::Init()
{
	aramakiAnime = new Anime("data/aramaki/aramaki.xml");
	aramakiAnime->SetAnime(startAnimeNo);
}

/*-------------------------------------------
	����
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
	�`��
--------------------------------------------*/
void EnemyObject::Draw()
{
	aramakiAnime->Draw(posX, posY);
}
