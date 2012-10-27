#pragma once

#include <DirectXLib.h>

class Boon : public DirectXLib
{
public:
	Boon();
	virtual ~Boon();

public:
	void Init();
	void Move();
	void Render();

private:
	Anime *boonAnime;
	Anime *bulletAnime;
	float posX;
	float posY;
	float accelY;
};
