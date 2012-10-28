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
	void Init();	// ‰Šú‰»
	void Move();	// ƒQ[ƒ€ˆ—
	void Render();	// •`‰æˆ—

private:
	Anime *logo;	// ƒƒS
};
