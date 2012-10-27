#include "StdAfx.h"
#include "GamePlayState.h"

/*-------------------------------------------
	�R���X�g���N�^
--------------------------------------------*/
GamePlayState::GamePlayState()
{
	stage = new Stage();
	boon = new Boon();
}

/*-------------------------------------------
	�f�X�g���N�^
--------------------------------------------*/
GamePlayState::~GamePlayState()
{
	delete stage;
	delete boon;
}

/*-------------------------------------------
	������
--------------------------------------------*/
void GamePlayState::Init()
{
	stage->Init();
	boon->Init();
}

/*-------------------------------------------
	�ړ�
--------------------------------------------*/
void GamePlayState::Move()
{
	stage->Move();
	boon->Move();
}

/*-------------------------------------------
	�`��
--------------------------------------------*/
void GamePlayState::Render()
{
	stage->Render();
	boon->Render();
}
