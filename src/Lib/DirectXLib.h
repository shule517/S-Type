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

	// テクスチャ描画
	void DrawTexture(LPDIRECT3DTEXTURE9 texture, int x, int y);
	void DrawTexture(LPDIRECT3DTEXTURE9 texture, int x, int y, RECT rect);
	void DrawTexture(LPDIRECT3DTEXTURE9 texture, int x, int y, int index);
	void DrawTexture(LPDIRECT3DTEXTURE9 texture, int x, int y, RECT rect, bool mirror);

	// 線描画
	void DrawLine(D3DXVECTOR2 startPos, D3DXVECTOR2 endPos);
	void DirectXLib::DrawBox(D3DXVECTOR2 startPos, D3DXVECTOR2 endPos);

	// タイトル変更
	void SetText(char* text);

	bool IsKeyDown(int key_no);
	float GetLoopTime(){ return loopTime; } // ループ時間を取得

private:
	static LPDIRECT3DDEVICE9 d3dDevice;
	static LPD3DXSPRITE sprite;
	static char keys[256];
	static float loopTime;
	static map<string, LPDIRECT3DTEXTURE9> textureMap;
	static ID3DXLine *d3dLine;
};
