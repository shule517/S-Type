#pragma once

#include "IObject.h"

class EnemyObject : public IObject
{
public:
	EnemyObject();
	virtual ~EnemyObject();

	void Init();	// ‰Šú‰»
	void Move();	// ˆÚ“®
	void Draw();	// •`‰æ
};
