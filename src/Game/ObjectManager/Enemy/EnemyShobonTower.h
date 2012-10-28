#pragma once

#include "EnemyObject.h"

class EnemyShobonTower : public EnemyObject
{
public:
	EnemyShobonTower(const long x, const long y, const long animeNo);
	virtual ~EnemyShobonTower();

	void Init();	// ������
	void Move();	// �ړ�
	void Draw();	// �`��

private:
	float accelY;			// �����xY
	float gravity;			// �d��
};
