#pragma once

class IGameState
{
public:
	IGameState(){}
	virtual ~IGameState(){}

	virtual void Init() = 0;	// ‰Šú‰»
	virtual void Move() = 0;	// ƒQ[ƒ€ˆ—
	virtual void Render() = 0;	// •`‰æˆ—
};
