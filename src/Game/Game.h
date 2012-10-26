#pragma once

#include "GameLib.h"
#include "Stage.h"
#include "Rockman.h"

class Game : public GameLib
{
public:
	Game(void);
	virtual ~Game(void);

private:
	void Init();	// ������
	void Move();	// �Q�[������
	void Render();	// �`�揈��

private:
	Stage *stage;
	Rockman *rockman;
};
