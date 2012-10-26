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
	void Init();	// 初期化
	void Move();	// ゲーム処理
	void Render();	// 描画処理

private:
	Stage *stage;
	Rockman *rockman;
};
