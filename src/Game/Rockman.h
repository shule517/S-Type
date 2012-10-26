#pragma once

class Rockman : public DirectXLib
{
public:
	Rockman(void);
	virtual ~Rockman(void);

public:
	void Init();
	void Move();
	void Render();

private:
	Anime *anime;
	bool isJump;
	float posX;
	float posY;
	float accelY;
	float gravity;

//	LPDIRECT3DTEXTURE9 texture;
};
