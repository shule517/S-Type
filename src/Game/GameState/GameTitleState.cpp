#include "StdAfx.h"
#include "GameTitleState.h"
#include "GameStateOperation.h"

/*-------------------------------------------
	コンストラクタ
--------------------------------------------*/
GameTitleState::GameTitleState()
{
	logo = new Anime("data/logo/logo.xml");
}

/*-------------------------------------------
	デストラクタ
--------------------------------------------*/
GameTitleState::~GameTitleState()
{
	delete logo;
}

/*-------------------------------------------
	初期化
--------------------------------------------*/
void GameTitleState::Init()
{
}

/*-------------------------------------------
	移動
------------------------------------ --------*/
void GameTitleState::Move()
{
	if (DirectXLib::GetInstance()->IsKeyDown(DIK_X))
	{
		GameStateOperation::GetInstance()->SetState();
	}
}

/*-------------------------------------------
	描画
--------------------------------------------*/
void GameTitleState::Render()
{
	logo->Draw(100, 100);
}
