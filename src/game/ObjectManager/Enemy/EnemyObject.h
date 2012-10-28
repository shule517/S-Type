#pragma once

#include "../IObject.h"

class Anime;
class EnemyObject : public IObject
{
public:
	EnemyObject(const long x, const long y, const long animeNo);
	virtual ~EnemyObject();

	void Init();	// ������
	void Move();	// �ړ�
	void Draw();	// �`��

private:
	Anime *aramakiAnime;	// �A�j��
	float accelY;			// �����xY
	float gravity;			// �d��
};
