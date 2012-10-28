#include "StdAfx.h"
#include "GameStateOperation.h"
#include <IGameState.h>

// TODO ����͂Ƃ肠�����Q�[�������
#include <GameState/GameTitleState.h>

/*-------------------------------------------
	�R���X�g���N�^
--------------------------------------------*/
GameStateOperation::GameStateOperation()
{
	// TODO ����͂Ƃ肠�����Q�[�������
	gameState = new GameTitleState();
}

/*-------------------------------------------
	�f�X�g���N�^
--------------------------------------------*/
GameStateOperation::~GameStateOperation()
{
	delete gameState;
}

/*-------------------------------------------
	������
--------------------------------------------*/
void GameStateOperation::Init()
{
	gameState->Init();
}

/*-------------------------------------------
	�Q�[������
--------------------------------------------*/
void GameStateOperation::Move()
{
	gameState->Move();
}

/*-------------------------------------------
	�`��
--------------------------------------------*/
void GameStateOperation::Render()
{
	gameState->Render();
}
