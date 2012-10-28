#pragma once

#include "EnemyObject.h"

class EnemyAramaki : public EnemyObject
{
public:
	EnemyAramaki(const long x, const long y, const long animeNo);
	virtual ~EnemyAramaki();

	void Init();	// ������
	void Move();	// �ړ�
	void Draw();	// �`��

private:
	float accelY;			// �����xY
	float gravity;			// �d��
};
