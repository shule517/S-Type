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
	void Init();	// 初期化
	void Move();	// ゲーム処理
	void Render();	// 描画処理

private:
	Anime *logo;	// ロゴ
};
