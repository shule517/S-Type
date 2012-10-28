#pragma once

#include "BulletObject.h"

class BulletMissile : public BulletObject
{
public:
	BulletMissile(const long x, const long y, const float dir);
	virtual ~BulletMissile();

	void Init();	// ������
	void Move();	// �ړ�
	void Draw();	// �`��

private:
	float accelY;			// �����xY
	float gravity;			// �d��
};
