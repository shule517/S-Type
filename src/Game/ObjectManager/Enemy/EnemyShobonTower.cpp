#include "StdAfx.h"
#include "EnemyShobonTower.h"
#include <DirectXLib.h>
#include <Anime.h>

/*-------------------------------------------
	�R���X�g���N�^
--------------------------------------------*/
EnemyShobonTower::EnemyShobonTower(const long x, const long y, const long animeNo)
:EnemyObject(x, y, animeNo),
accelY(1.1f),
gravity(0.01f)
{
	posX = x;
	posY = y;
	startAnimeNo = animeNo;
	life = 5;
}

/*-------------------------------------------
	�f�X�g���N�^
--------------------------------------------*/
EnemyShobonTower::~EnemyShobonTower()
{
	delete anime;
}

/*-------------------------------------------
	������
--------------------------------------------*/
void EnemyShobonTower::Init()
{
	anime = new Anime("data/EnemyShobonTower/EnemyShobonTower.xml");
	anime->SetAnime(startAnimeNo);
}

/*-------------------------------------------
	����
--------------------------------------------*/
void EnemyShobonTower::Move()
{
}

/*-------------------------------------------
	�`��
--------------------------------------------*/
void EnemyShobonTower::Draw()
{
	D3DXVECTOR2 pos = GetClientPos();
	anime->Draw(pos.x, pos.y);
}
