#pragma once

#include "../IObject.h"

class Anime;
class EnemyObject : public IObject
{
public:
	EnemyObject(const long x, const long y, const long animeNo);
	virtual ~EnemyObject();

	// �ȉ��́A�e��ۃN���X�Ŏ�������
	// void Init();	// ������
	// void Move();	// �ړ�
	// void Draw();	// �`��

protected:
	Anime *anime;	// �A�j��
};
