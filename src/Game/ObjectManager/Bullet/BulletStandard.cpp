#include "StdAfx.h"
#include "BulletStandard.h"
#include <DirectXLib.h>
#include <Anime.h>

const long speed = 40.0f;

/*-------------------------------------------
	�R���X�g���N�^
--------------------------------------------*/
BulletStandard::BulletStandard(const long x, const long y, const float dir)
:BulletObject(x, y, dir),
accelY(1.1f),
gravity(1.0f)
{
	// TODO �����ŃA�j���ԍ������炤�K�v�L��H
	posX = x;
	posY = y;
	startAnimeNo = 0;
}

/*-------------------------------------------
	�f�X�g���N�^
--------------------------------------------*/
BulletStandard::~BulletStandard()
{
	delete anime;
}

/*-------------------------------------------
	������
--------------------------------------------*/
void BulletStandard::Init()
{
	anime = new Anime("data/bullet/StandardBullet.xml");
	anime->SetAnime(startAnimeNo);
}

/*-------------------------------------------
	����
--------------------------------------------*/
void BulletStandard::Move()
{
	posX += speed;//DirectXLib::GetInstance()->GetMove(speed);
}

/*-------------------------------------------
	�`��
--------------------------------------------*/
void BulletStandard::Draw()
{
	D3DXVECTOR2 pos = GetClientPos();
	anime->Draw(pos.x, pos.y);
}
