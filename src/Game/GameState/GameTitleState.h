#pragma once

#include "GameLib.h"
#include "ObjectManager/Stage/Stage.h"
#include "ObjectManager/Boon/Boon.h"
#include <IGameState.h>

class GameTitleState : public IGameState
{
public:
	GameTitleState();
	virtual ~GameTitleState();

private:
	void Init();	// ������
	void Move();	// �Q�[������
	void Render();	// �`�揈��

private:
	Anime *logo;	// ���S
};
