#include "StdAfx.h"
#include "BulletStandard.h"
#include <DirectXLib.h>
#include <Anime.h>

const long speed = 40.0f;

/*-------------------------------------------
	コンストラクタ
--------------------------------------------*/
BulletStandard::BulletStandard(const long x, const long y, const float dir)
:BulletObject(x, y, dir),
accelY(1.1f),
gravity(1.0f)
{
	// TODO 引数でアニメ番号をもらう必要有り？
	posX = x;
	posY = y;
	startAnimeNo = 0;
}

/*-------------------------------------------
	デストラクタ
--------------------------------------------*/
BulletStandard::~BulletStandard()
{
	delete anime;
}

/*-------------------------------------------
	初期化
--------------------------------------------*/
void BulletStandard::Init()
{
	anime = new Anime("data/bullet/StandardBullet.xml");
	anime->SetAnime(startAnimeNo);
}

/*-------------------------------------------
	動作
--------------------------------------------*/
void BulletStandard::Move()
{
	posX += speed;//DirectXLib::GetInstance()->GetMove(speed);
}

/*-------------------------------------------
	描画
--------------------------------------------*/
void BulletStandard::Draw()
{
	D3DXVECTOR2 pos = GetClientPos();
	anime->Draw(pos.x, pos.y);
}
