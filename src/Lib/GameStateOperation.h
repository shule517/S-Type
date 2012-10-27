#pragma once

class IGameState;
class GameStateOperation
{
public:
	GameStateOperation();
	virtual ~GameStateOperation();

	void Init();
	void Move();
	void Render();

private:
	IGameState *gameState;	// ƒQ[ƒ€ó‘Ô.
};
