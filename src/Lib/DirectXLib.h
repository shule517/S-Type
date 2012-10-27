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

	// �e�N�X�`���`��
	void DrawTexture(LPDIRECT3DTEXTURE9 texture, int x, int y);
	void DrawTexture(LPDIRECT3DTEXTURE9 texture, int x, int y, RECT rect);
	void DrawTexture(LPDIRECT3DTEXTURE9 texture, int x, int y, int index);
	void DrawTexture(LPDIRECT3DTEXTURE9 texture, int x, int y, RECT rect, bool mirror);

	// ���`��
	void DrawLine(D3DXVECTOR2 startPos, D3DXVECTOR2 endPos);
	void DirectXLib::DrawBox(D3DXVECTOR2 startPos, D3DXVECTOR2 endPos);

	// �^�C�g���ύX
	void SetText(char* text);

	bool IsKeyDown(int key_no);
	float GetLoopTime(){ return loopTime; } // ���[�v���Ԃ��擾

private:
	LPDIRECT3DDEVICE9 d3dDevice;
	LPD3DXSPRITE sprite;
	char keys[256];
	float loopTime;
	map<string, LPDIRECT3DTEXTURE9> textureMap;		// TODO �|�C���^����ꂽ�����ǂ��H
	ID3DXLine *d3dLine;

	// �C���X�^���X
	static DirectXLib *instance;
};
