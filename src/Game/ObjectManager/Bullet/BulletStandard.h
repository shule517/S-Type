#pragma once

#include "BulletObject.h"

class BulletStandard : public BulletObject
{
public:
	BulletStandard(const long x, const long y, const float dir);
	virtual ~BulletStandard();

	void Init();	// ������
	void Move();	// �ړ�
	void Draw();	// �`��

private:
	float accelY;			// �����xY
	float gravity;			// �d��
};
