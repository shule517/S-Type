#pragma once

#include "GameLib.h"
#include "ObjectManager/Stage/Stage.h"
#include "ObjectManager/Boon/Boon.h"
#include <IGameState.h>

class GamePlayState : public IGameState
{
public:
	GamePlayState();
	virtual ~GamePlayState();

private:
	void Init();	// ������
	void Move();	// �Q�[������
	void Render();	// �`�揈��

private:
	Stage *stage;	// �X�e�[�W
	Boon *boon;		// �u�[��
};
