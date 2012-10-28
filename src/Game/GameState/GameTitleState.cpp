#include "StdAfx.h"
#include "GameTitleState.h"
#include "GameStateOperation.h"

/*-------------------------------------------
	�R���X�g���N�^
--------------------------------------------*/
GameTitleState::GameTitleState()
{
	logo = new Anime("data/logo/logo.xml");
}

/*-------------------------------------------
	�f�X�g���N�^
--------------------------------------------*/
GameTitleState::~GameTitleState()
{
	delete logo;
}

/*-------------------------------------------
	������
--------------------------------------------*/
void GameTitleState::Init()
{
}

/*-------------------------------------------
	�ړ�
------------------------------------ --------*/
void GameTitleState::Move()
{
	if (DirectXLib::GetInstance()->IsKeyDown(DIK_X))
	{
		GameStateOperation::GetInstance()->SetState();
	}
}

/*-------------------------------------------
	�`��
--------------------------------------------*/
void GameTitleState::Render()
{
	logo->Draw(100, 100);
}
