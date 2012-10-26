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
	void Init();	// ‰Šú‰»
	void Move();	// ƒQ[ƒ€ˆ—
	void Render();	// •`‰æˆ—

private:
	Stage *stage;
	Rockman *rockman;
};
