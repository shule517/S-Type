#pragma once

#include <GameState/GamePlayState.h>

class IGameState;
class GameStateOperation
{
public:
	// TODO ‹­ˆø’ˆÓ
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

	// TODO ‹­ˆø’ˆÓ
	void SetState()
	{
		delete gameState;
		gameState = new GamePlayState();
		gameState->Init();
	}

private:
	IGameState *gameState;	// ƒQ[ƒ€ó‘Ô.
};
