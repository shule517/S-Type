#pragma once

class DirectXLib
{
public:
	DirectXLib();
	virtual ~DirectXLib();

public:
	static void Init(LPDIRECT3DDEVICE9 _d3dDevice, LPD3DXSPRITE _sprite)
	{
		d3dDevice = _d3dDevice;
		sprite = _sprite;
	}

	static void SetKeyState(char *_keys)
	{
		for (int i = 0; i < 256; i++)
		{
			keys[i] = _keys[i];
		}
	}

	static void SetLoopTime(float time)
	{
		loopTime = time;
	}

public:
	LPDIRECT3DTEXTURE9 LoadTexture(const char *file_name);
	void DrawTexture(LPDIRECT3DTEXTURE9 texture, int x, int y);
	void DrawTexture(LPDIRECT3DTEXTURE9 texture, int x, int y, RECT rect);
	void DrawTexture(LPDIRECT3DTEXTURE9 texture, int x, int y, int index);
	void DrawTexture(LPDIRECT3DTEXTURE9 texture, int x, int y, RECT rect, bool mirror);
	void SetText(char* text);

	bool IsKeyDown(int key_no);
	float GetLoopTime(){ return loopTime; } // ƒ‹[ƒvŽžŠÔ‚ðŽæ“¾

private:
	static LPDIRECT3DDEVICE9 d3dDevice;
	static LPD3DXSPRITE sprite;
	static char keys[256];
	static float loopTime;
	static map<string, LPDIRECT3DTEXTURE9> textureMap;
};
