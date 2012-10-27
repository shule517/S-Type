#include "StdAfx.h"
#include "GameStateOperation.h"
#include <IGameState.h>
#include <GamePlayState.h>

/*-------------------------------------------
	コンストラクタ
--------------------------------------------*/
GameStateOperation::GameStateOperation()
{
	// TODO 今回はとりあえずゲーム中状態
	gameState = new GamePlayState();
}

/*-------------------------------------------
	デストラクタ
--------------------------------------------*/
GameStateOperation::~GameStateOperation()
{
	delete gameState;
}

/*-------------------------------------------
	初期化
--------------------------------------------*/
void GameStateOperation::Init()
{
	gameState->Init();
}

/*-------------------------------------------
	ゲーム処理
--------------------------------------------*/
void GameStateOperation::Move()
{
	gameState->Move();
}

/*-------------------------------------------
	描画
--------------------------------------------*/
void GameStateOperation::Render()
{
	gameState->Render();
}
