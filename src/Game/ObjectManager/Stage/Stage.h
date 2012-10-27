#pragma once

#include "../IObject.h"

class Stage : public IObject
{
public:
	Stage();
	virtual ~Stage();

public:
	void Init();
	void Move();
	void Draw();

private:
	LPDIRECT3DTEXTURE9 texture;
};
