#include "StdAfx.h"
#include "GameStateOperation.h"
#include <IGameState.h>

// TODO 今回はとりあえずゲーム中状態
#include <GameState/GameTitleState.h>

/*-------------------------------------------
	コンストラクタ
--------------------------------------------*/
GameStateOperation::GameStateOperation()
{
	// TODO 今回はとりあえずゲーム中状態
	gameState = new GameTitleState();
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
