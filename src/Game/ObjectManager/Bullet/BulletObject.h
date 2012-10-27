#pragma once

#include "../IObject.h"

class BulletObject : public IObject
{
public:
	BulletObject();
	virtual ~BulletObject();

	void Init();	// ‰Šú‰»
	void Move();	// ˆÚ“®
	void Draw();	// •`‰æ
};
