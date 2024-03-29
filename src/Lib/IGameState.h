#pragma once

class IGameState
{
public:
	IGameState(){}
	virtual ~IGameState(){}

	virtual void Init() = 0;	// 初期化
	virtual void Move() = 0;	// ゲーム処理
	virtual void Render() = 0;	// 描画処理
};
