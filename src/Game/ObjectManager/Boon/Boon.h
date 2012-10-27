#pragma once

#include "../IObject.h"

class Boon : public IObject
{
public:
	Boon();
	virtual ~Boon();

public:
	void Init();
	void Move();
	void Draw();

private:
	Anime *boonAnime;
	Anime *bulletAnime;
};
