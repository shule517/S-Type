#pragma once

class IGameState
{
public:
	IGameState(){}
	virtual ~IGameState(){}

	virtual void Init() = 0;	// ������
	virtual void Move() = 0;	// �Q�[������
	virtual void Render() = 0;	// �`�揈��
};
