#pragma once

#include "IObject.h"

class EnemyObject : public IObject
{
public:
	EnemyObject();
	virtual ~EnemyObject();

	void Init();	// ������
	void Move();	// �ړ�
	void Draw();	// �`��
};
