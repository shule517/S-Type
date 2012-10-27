#include "StdAfx.h"
#include "Boon.h"

const float FALL_RATE = 10.0f;
const float MOVE_SPEED = 4.0f;

const float JUMP_POWER = 1.5f;
const float GRAVITY_POWER = 0.4f;
const float FALL_JUDGE = -4.5f;
const float GRAVITY_RATE = 0.8f;


Boon::Boon()
{
	posX = 0;
	posY = 0;
	accelY = 0;
}

Boon::~Boon()
{
	delete boonAnime;
	delete bulletAnime;
}

void Boon::Init()
{
	boonAnime = new Anime("data/rockman.xml");
	bulletAnime = new Anime("data/tama.xml");
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

void Boon::Render()
{
	static bool isBuster = false;

	if (!IsKeyDown(DIK_X))
	{
		isBuster = false;
	}

	// òAéÀ
	if (IsKeyDown(DIK_X))
	{
		static DWORD time = timeGetTime();

		// 100msòAë≈
		if ((timeGetTime() - time) > 100)
		{
			// PlaySound("data/buster.wav", NULL, SND_FILENAME | SND_ASYNC);

			TamaData t;
			t.x = (256.0f / 2.0f) + (boonAnime->getMirror() ? -35 : 5);;
			t.y = 163.0f + posY;
			t.accelX = 15.0f * (boonAnime->getMirror() ? -1 : 1);
			tamaList.push_back(t);
			isBuster = true;

			time = timeGetTime();
		}
	}

	// ç∂âEà⁄ìÆ
	if (IsKeyDown(DIK_LEFT))
	{
		posX -= MOVE_SPEED;
		boonAnime->setMirror(true);
	}
	else if (IsKeyDown(DIK_RIGHT))
	{
		posX += MOVE_SPEED;
		boonAnime->setMirror(false);
	}

	// è„â∫à⁄ìÆ
	if (IsKeyDown(DIK_UP))
	{
		posY -= MOVE_SPEED;
	}
	else if (IsKeyDown(DIK_DOWN))
	{
		posY += MOVE_SPEED;
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
