#include "StdAfx.h"
#include "EnemyAramaki.h"
#include <DirectXLib.h>
#include <Anime.h>

/*-------------------------------------------
	�R���X�g���N�^
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
	�f�X�g���N�^
--------------------------------------------*/
EnemyAramaki::~EnemyAramaki()
{
	delete anime;
}

/*-------------------------------------------
	������
--------------------------------------------*/
void EnemyAramaki::Init()
{
	anime = new Anime("data/aramaki/aramaki.xml");
	anime->SetAnime(startAnimeNo);
}

/*-------------------------------------------
	����
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
	�`��
--------------------------------------------*/
void EnemyAramaki::Draw()
{
	D3DXVECTOR2 pos = GetClientPos();
	anime->Draw(pos.x, pos.y);
}
