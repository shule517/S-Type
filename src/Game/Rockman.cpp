#include "StdAfx.h"
#include "Rockman.h"

const float FALL_RATE = 10.0f;
const float MOVE_SPEED = 4.0f;

const float JUMP_POWER = 1.5f;
const float GRAVITY_POWER = 0.4f;
const float FALL_JUDGE = -4.5f;
const float GRAVITY_RATE = 0.8f;

bool isJumpKey = true;

Anime *tamaAnime;

Rockman::Rockman(void)
{
	posX = 0;
	posY = 0;
	accelY = 0;
	gravity = GRAVITY_POWER;
	isJump = false;
}

Rockman::~Rockman(void)
{
	delete anime;
}

void Rockman::Init()
{
	anime = new Anime("data/rockman.xml");
	tamaAnime = new Anime("data/tama.xml");
}

void Rockman::Move()
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

void Rockman::Render()
{
	// マップデータ
	int mapdata[16][39] =
	{
		{210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210},
		{210, 210,  50,  51, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210,  50,  51, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210},
		{210, 210,  66,  67, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210,  66,  67, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210},
		{210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210},
		{210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210},
		{210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210},
		{210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210},
		{210, 129, 210, 210, 210, 129, 210, 210, 210, 210, 210, 210, 129, 210, 210, 210, 210, 129, 210, 210, 129, 210, 210, 210, 129, 210, 210, 210, 210, 210, 210, 129, 210, 210, 210, 210, 129, 210, 210},
		{210, 145, 210, 210, 210, 145, 210, 210, 210, 210, 210, 210, 145, 210, 210, 210, 210, 145, 210, 210, 145, 210, 210, 210, 145, 210, 210, 210, 210, 210, 210, 145, 210, 210, 210, 210, 145, 210, 210},
		{160, 161, 162, 210, 160, 161, 162, 210, 129, 210, 210, 160, 161, 162, 210, 210, 160, 161, 162, 210, 161, 162, 210, 160, 161, 162, 210, 129, 210, 210, 160, 161, 162, 210, 210, 160, 161, 162, 210},
		{176, 177, 178, 210, 176, 177, 178, 210, 145, 210, 210, 176, 177, 178, 210, 210, 176, 177, 178, 210, 177, 178, 210, 176, 177, 178, 210, 145, 210, 210, 176, 177, 178, 210, 210, 176, 177, 178, 210},
		{192, 193, 194, 210, 192, 193, 194, 160, 161, 162, 210, 192, 193, 194, 210, 210, 192, 193, 194, 210, 193, 194, 210, 192, 193, 194, 160, 161, 162, 210, 192, 193, 194, 210, 210, 192, 193, 194, 210},
		{245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246},
		{245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246},
		{  0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1},
		{ 16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17},
	};

	// マップ描画
	for (int y = 0; y < 16; y++)
	{
		for (int x = 0; x < 39; x++)
		{
//			DrawTexture(LoadTexture("stg_freeze.bmp"), (x * 16 - posX), ((y-1) * 16 - posY), mapdata[y][x]);
//			DrawTexture(LoadTexture("data/stg_freeze.bmp"), (x * 16 - (int)posX), ((y-1) * 16) - 16, mapdata[y][x]);
		}
	}
	static bool btest = true;

	if (IsKeyDown(DIK_Z) == false)
	{
		isJumpKey = true;
	}

	static bool isBuster = false;

	if (!IsKeyDown(DIK_X))
	{
		isBuster = false;
	}

	// 着地中
	if (isJump == false)
	{
		// ジャンプ
		if (IsKeyDown(DIK_Z) && isJumpKey)
		{
			isJumpKey = false;

			accelY = -JUMP_POWER;
			isJump = true;
			gravity = GRAVITY_POWER;

			btest = true;

			anime->setAnime(2);
		}
		// 走り
		else if (IsKeyDown(DIK_LEFT) || IsKeyDown(DIK_RIGHT))
		{
			anime->setAnime(1);
		}
		// 立ち
		else
		{
			anime->setAnime(0);
		}

	}

	char data[256];
	sprintf_s(data, "accelY = %f", accelY);
	//SetText(data);

	// ジャンプ中
	if (isJump == true)
	{
		// ジャンプボタンが離されたか？
		if (IsKeyDown(DIK_Z))
		{
			if (btest)
			{
				if (accelY > FALL_JUDGE)
				{
					accelY -= GRAVITY_RATE;
				}
				else
				{
					btest = false;
				}
			}
		}
		else
		{
			btest = false;
		}

		accelY += gravity;
		posY += accelY;

		// 着地
		if (posY > 0)
		{
			PlaySound("data/tyakuti.wav", NULL, SND_FILENAME | SND_ASYNC);

			posY = 0;
			isJump = false;
		}
	}

	// 連射
	if (IsKeyDown(DIK_X))
	{
		static DWORD time = timeGetTime();


		// 100ms連打
		if ((timeGetTime() - time) > 100)
		{
			// PlaySound("data/buster.wav", NULL, SND_FILENAME | SND_ASYNC);

			TamaData t;
			t.x = (256.0f / 2.0f) + (anime->getMirror() ? -35 : 5);;
			t.y = 163.0f + posY;
			t.accelX = 15.0f * (anime->getMirror() ? -1 : 1);
			tamaList.push_back(t);
			isBuster = true;

			time = timeGetTime();
		}

		/*
		if (!isBuster)
		{
			PlaySound("data/buster.wav", NULL, SND_FILENAME | SND_ASYNC);

			TamaData t;
			t.x = 256/2 + (anime->getMirror() ? -35 : 5);;
			t.y = 163 + posY;
			t.accelX = 4 * (anime->getMirror() ? -1 : 1);
			tamaList.push_back(t);
			isBuster = true;

			time = timeGetTime();
		}

		if (!isJump)
		{
			// 走りバスター
			if (IsKeyDown(DIK_LEFT) || IsKeyDown(DIK_RIGHT))
			{
				anime->setAnime(4);
			}
			// 通常バスター
			else
			{
				anime->setAnime(3);
			}
		}
		else
		{
			// ジャンプバスター
			anime->setAnime(5);
		}
		*/
	}


	// 左右移動
	if (IsKeyDown(DIK_LEFT))
	{
		posX -= MOVE_SPEED;
		anime->setMirror(true);
	}
	else if (IsKeyDown(DIK_RIGHT))
	{
		posX += MOVE_SPEED;
		anime->setMirror(false);
	}

	// 上下移動
	if (IsKeyDown(DIK_UP))
	{
		posY -= MOVE_SPEED;
	}
	else if (IsKeyDown(DIK_DOWN))
	{
		posY += MOVE_SPEED;
	}

	// 描画
	anime->Draw(posX, 160 + (int)posY);

	// 弾を描画
	list<TamaData>::iterator it;
	for(it = tamaList.begin(); it != tamaList.end(); )
	{
		tamaAnime->Draw((*it).x, (*it).y);
		(*it).x += (*it).accelX;

		char data[256];
		sprintf(data, "%f", (*it).x);
		//MessageBox(0, data, 0, 0);

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
