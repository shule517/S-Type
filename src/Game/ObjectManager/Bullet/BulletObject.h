#pragma once

#include "../IObject.h"

class BulletObject : public IObject
{
public:
	BulletObject();
	virtual ~BulletObject();

	void Init();	// ������
	void Move();	// �ړ�
	void Draw();	// �`��
};
