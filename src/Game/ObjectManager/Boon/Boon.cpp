#include "StdAfx.h"
#include "Boon.h"

const float MOVE_SPEED = 4.0f;

Boon::Boon()
{
}

Boon::~Boon()
{
	delete boonAnime;
	delete bulletAnime;
}

void Boon::Init()
{
	boonAnime = new Anime("data/boon/boon.xml");
	bulletAnime = new Anime("data/boon/bullet.xml");
}

void Boon::Move()
{
}

class TamaData
{
public:
	float x;
	float y;
	float accelX;
};

list<TamaData> tamaList;

void Boon::Draw()
{
	static bool isBuster = false;

	if (!DirectXLib::GetInstance()->IsKeyDown(DIK_X))
	{
		isBuster = false;
	}

	// òAéÀ
	if (DirectXLib::GetInstance()->IsKeyDown(DIK_X))
	{
		static DWORD time = timeGetTime();

		// 100msòAë≈
		if ((timeGetTime() - time) > 100)
		{
			// PlaySound("data/buster.wav", NULL, SND_FILENAME | SND_ASYNC);

			TamaData t;
			t.x = (256.0f / 2.0f) + (boonAnime->GetMirror() ? -35 : 5);;
			t.y = 163.0f + posY;
			t.accelX = 15.0f * (boonAnime->GetMirror() ? -1 : 1);
			tamaList.push_back(t);
			isBuster = true;

			time = timeGetTime();
		}
	}

	// ç∂âEà⁄ìÆ
	if (DirectXLib::GetInstance()->IsKeyDown(DIK_LEFT))
	{
		posX -= static_cast<long>(MOVE_SPEED);
		boonAnime->SetMirror(true);
	}
	else if (DirectXLib::GetInstance()->IsKeyDown(DIK_RIGHT))
	{
		posX += static_cast<long>(MOVE_SPEED);
		boonAnime->SetMirror(false);
	}

	// è„â∫à⁄ìÆ
	if (DirectXLib::GetInstance()->IsKeyDown(DIK_UP))
	{
		posY -= static_cast<long>(MOVE_SPEED);
	}
	else if (DirectXLib::GetInstance()->IsKeyDown(DIK_DOWN))
	{
		posY += static_cast<long>(MOVE_SPEED);
	}

	// é©ã@ï`âÊ
	boonAnime->Draw(static_cast<int>(posX), 160 + static_cast<int>(posY));

	// íeÇï`âÊ
	list<TamaData>::iterator it;
	for(it = tamaList.begin(); it != tamaList.end(); )
	{
		// ï`âÊ.
		bulletAnime->Draw(static_cast<int>((*it).x), static_cast<int>((*it).y));
		(*it).x += (*it).accelX;

		// âÊñ äOÇ≈íeÇè¡Ç∑.
		if (0 < (*it).x || (*it).x < 800)
		{
			it++;
		}
		else
		{
			it = tamaList.erase(it);
		}
	}
}
