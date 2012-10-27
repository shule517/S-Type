#pragma once

class Stage : public DirectXLib
{
public:
	Stage();
	virtual ~Stage();

public:
	void Init();
	void Move();
	void Render();

private:
	LPDIRECT3DTEXTURE9 texture;
};
