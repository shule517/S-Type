#pragma once

#include "../IObject.h"

class Boon : public IObject
{
public:
	static Boon* GetInstance()
	{
		static Boon instance;
		return &instance;
	}
private:
	Boon();
	virtual ~Boon();

public:
	void Init();
	void Move();
	void Draw();

	void Hit()
	{
		life--;

		if (life == 0)
		{
			PlaySound("data/se/death.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
	}

private:
	Anime *anime;
	Anime *bulletAnime;
};
