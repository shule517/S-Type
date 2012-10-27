#include "StdAfx.h"
#include "GamePlayState.h"

/*-------------------------------------------
	コンストラクタ
--------------------------------------------*/
GamePlayState::GamePlayState()
{
	stage = new Stage();
	boon = new Boon();
}

/*-------------------------------------------
	デストラクタ
--------------------------------------------*/
GamePlayState::~GamePlayState()
{
	delete stage;
	delete boon;
}

/*-------------------------------------------
	初期化
--------------------------------------------*/
void GamePlayState::Init()
{
	stage->Init();
	boon->Init();
}

/*-------------------------------------------
	移動
--------------------------------------------*/
void GamePlayState::Move()
{
	stage->Move();
	boon->Move();
}

/*-------------------------------------------
	描画
--------------------------------------------*/
void GamePlayState::Render()
{
	stage->Render();
	boon->Render();
}
