#pragma once

#include <GameState/GamePlayState.h>

class IGameState;
class GameStateOperation
{
public:
	// TODO 強引注意
	static GameStateOperation* GetInstance()
	{
		static GameStateOperation instance;
		return &instance;
	}

private:
	GameStateOperation();
	virtual ~GameStateOperation();

public:
	void Init();
	void Move();
	void Render();

	// TODO 強引注意
	void SetState()
	{
		delete gameState;
		gameState = new GamePlayState();
		gameState->Init();
	}

private:
	IGameState *gameState;	// ゲーム状態.
};
