#include "StdAfx.h"
#include "BulletMissile.h"
#include <DirectXLib.h>
#include <Anime.h>

/*-------------------------------------------
	�R���X�g���N�^
--------------------------------------------*/
BulletMissile::BulletMissile(const long x, const long y, const float dir)
:BulletObject(x, y, dir),
accelY(1.1f),
gravity(1.0f)
{
	// TODO �����ŃA�j���ԍ������炤�K�v�L��H
	posX = x;
	posY = y;
	startAnimeNo = 0;
	life = 10;
}

/*-------------------------------------------
	�f�X�g���N�^
--------------------------------------------*/
BulletMissile::~BulletMissile()
{
	delete anime;
}

/*-------------------------------------------
	������
--------------------------------------------*/
void BulletMissile::Init()
{
	anime = new Anime("data/aramaki/aramaki.xml");
	anime->SetAnime(startAnimeNo);
}

/*-------------------------------------------
	����
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
	�`��
--------------------------------------------*/
void BulletMissile::Draw()
{
	D3DXVECTOR2 pos = GetClientPos();
	anime->Draw(pos.x, pos.y);
}
