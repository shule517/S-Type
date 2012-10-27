#include "StdAfx.h"
#include "EnemyObject.h"
#include <DirectXLib.h>
#include <Anime.h>

/*-------------------------------------------
	�R���X�g���N�^
--------------------------------------------*/
EnemyObject::EnemyObject(long x, long y)
{
	posX = x;
	posY = y;
	accelY = 1.1;
	gravity = 0.4;
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
}

/*-------------------------------------------
	����
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
	�`��
--------------------------------------------*/
void EnemyObject::Draw()
{
	aramakiAnime->Draw(posX, posY);
}
