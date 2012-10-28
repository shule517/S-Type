#pragma once

#include "../IObject.h"

class BulletObject : public IObject
{
public:
	BulletObject(const long x, const long y, const float dir);
	virtual ~BulletObject();

	void Init();	// ������
	void Move();	// �ړ�
	void Draw();	// �`��

private:
	float bulletDir;	// �e����
};
