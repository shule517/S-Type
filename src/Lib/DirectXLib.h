#pragma once

class DirectXLib
{
public:
	static DirectXLib* GetInstance();

private:
	DirectXLib();
	virtual ~DirectXLib();

public:
	void Init(LPDIRECT3DDEVICE9 _d3dDevice, LPD3DXSPRITE _sprite);
	void SetKeyState(char *_keys);
	void SetLoopTime(float time);

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
	LPDIRECT3DDEVICE9 d3dDevice;
	LPD3DXSPRITE sprite;
	char keys[256];
	float loopTime;
	map<string, LPDIRECT3DTEXTURE9> textureMap;		// TODO ポインタを入れた方が良い？
	ID3DXLine *d3dLine;

	// インスタンス
	static DirectXLib *instance;
};
