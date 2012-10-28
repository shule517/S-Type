#include "StdAfx.h"
#include "Boon.h"

const float MOVE_SPEED = 4.0f;

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

	// �A��
	if (DirectXLib::GetInstance()->IsKeyDown(DIK_X))
	{
		static DWORD time = timeGetTime();

		// 100ms�A��
		if ((timeGetTime() - time) > 100)
		{
			// PlaySound("data/buster.wav", NULL, SND_FILENAME | SND_ASYNC);

			TamaData t;
			t.x = (256.0f / 2.0f) + (anime->GetMirror() ? -35 : 5);;
			t.y = 163.0f + posY;
			t.accelX = 15.0f * (anime->GetMirror() ? -1 : 1);
			tamaList.push_back(t);
			isBuster = true;

			time = timeGetTime();
		}
	}

	// �����E�X�N���[��(�b��100dot)
	posX += DirectXLib::GetInstance()->GetMove(100);

	// ���E�ړ�
	if (DirectXLib::GetInstance()->IsKeyDown(DIK_LEFT))
	{
		posX -= static_cast<long>(MOVE_SPEED);
		anime->SetMirror(true);
	}
	else if (DirectXLib::GetInstance()->IsKeyDown(DIK_RIGHT))
	{
		posX += static_cast<long>(MOVE_SPEED);
		anime->SetMirror(false);
	}

	// �㉺�ړ�
	if (DirectXLib::GetInstance()->IsKeyDown(DIK_UP))
	{
		posY -= static_cast<long>(MOVE_SPEED);
	}
	else if (DirectXLib::GetInstance()->IsKeyDown(DIK_DOWN))
	{
		posY += static_cast<long>(MOVE_SPEED);
	}

	// ���@�`��
	D3DXVECTOR2 pos = GetClientPos();
	anime->Draw(pos.x, pos.y);

	// �e��`��
	list<TamaData>::iterator it;
	for(it = tamaList.begin(); it != tamaList.end(); )
	{
		// �`��.
		bulletAnime->Draw(static_cast<int>((*it).x), static_cast<int>((*it).y));
		(*it).x += (*it).accelX;

		// ��ʊO�Œe������.
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
