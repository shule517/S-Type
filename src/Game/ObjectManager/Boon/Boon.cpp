#include "StdAfx.h"
#include "Boon.h"
#include "../Bullet/BulletManager.h"

const float MOVE_SPEED = 500.0f;

Boon::Boon()
{
}

Boon::~Boon()
{
	delete anime;
	delete bulletAnime;
}

void Boon::Init()
{
	anime = new Anime("data/boon/boon.xml");
	bulletAnime = new Anime("data/boon/bullet.xml");
}

void Boon::Move()
{
}

void Boon::Draw()
{
	if (life <= 0)
	{
		return;
	}

	// ’e˜AŽË
	if (DirectXLib::GetInstance()->IsKeyDown(DIK_X))
	{
		static DWORD time = timeGetTime();

		// 100ms˜A‘Å
		if ((timeGetTime() - time) > 100)
		{
			// ’e”­ŽË
			BulletManager::GetInstance()->ShootBullet(OBJECT_BULLET_STANDARD, static_cast<float>(posX + 130), static_cast<float>(posY), 0);
			PlaySound("data/se/tm2_shoot001.wav", NULL, SND_FILENAME | SND_ASYNC);
			time = timeGetTime();
		}
	}

	// ’e˜AŽË
	if (DirectXLib::GetInstance()->IsKeyDown(DIK_Z))
	{
		static DWORD time = timeGetTime();

		// 100ms˜A‘Å
		if ((timeGetTime() - time) > 100)
		{
			// ’e”­ŽË
			BulletManager::GetInstance()->ShootBullet(OBJECT_BULLET_MISSILE, static_cast<float>(posX + 130), static_cast<float>(posY), 0);
			PlaySound("data/se/tm2_sonic002.wav", NULL, SND_FILENAME | SND_ASYNC);
			time = timeGetTime();
		}
	}

	// Ž©“®‰EƒXƒNƒ[ƒ‹(•bŠÔ100dot)
	posX += DirectXLib::GetInstance()->GetMove(100);

	// ¶‰EˆÚ“®
	if (DirectXLib::GetInstance()->IsKeyDown(DIK_LEFT))
	{
		posX -= DirectXLib::GetInstance()->GetMove(MOVE_SPEED);
	}
	else if (DirectXLib::GetInstance()->IsKeyDown(DIK_RIGHT))
	{
		posX += DirectXLib::GetInstance()->GetMove(MOVE_SPEED);
	}

	// ã‰ºˆÚ“®
	if (DirectXLib::GetInstance()->IsKeyDown(DIK_UP))
	{
		posY -= DirectXLib::GetInstance()->GetMove(MOVE_SPEED);
	}
	else if (DirectXLib::GetInstance()->IsKeyDown(DIK_DOWN))
	{
		posY += DirectXLib::GetInstance()->GetMove(MOVE_SPEED);
	}

	// Ž©‹@•`‰æ
	D3DXVECTOR2 pos = GetClientPos();
	anime->Draw(pos.x, pos.y);
}
