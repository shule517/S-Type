#pragma once

#include "../IObject.h"

class Anime;

// �e�I�u�W�F�N�g
class BulletObject : public IObject
{
public:
	BulletObject(const long x, const long y, const float dir);
	virtual ~BulletObject();

	// �ȉ��́A�e��ۃN���X�Ŏ�������
	// void Init();	// ������
	// void Move();	// �ړ�
	// void Draw();	// �`��
	void Hit(){ life--; };

protected:
	Anime *anime;		// �e�A�j��
	float bulletDir;	// �e����
};
