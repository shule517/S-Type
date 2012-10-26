#pragma once

class Stage : public DirectXLib
{
public:
	Stage(void);
	virtual ~Stage(void);

public:
	void Init();
	void Move();
	void Render();

private:
	LPDIRECT3DTEXTURE9 texture;
};
