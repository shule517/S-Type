#include "StdAfx.h"
#include "DirectXLib.h"

/*-------------------------------------------
	静的変数の初期化
--------------------------------------------*/
LPDIRECT3DDEVICE9 DirectXLib::d3dDevice = NULL;
LPD3DXSPRITE DirectXLib::sprite = NULL;
char DirectXLib::keys[256];
float DirectXLib::loopTime;
map<string, LPDIRECT3DTEXTURE9> DirectXLib::textureMap;


/*-------------------------------------------
	コンストラクタ
--------------------------------------------*/
DirectXLib::DirectXLib(void)
{
}

/*-------------------------------------------
	デストラクタ
--------------------------------------------*/
DirectXLib::~DirectXLib(void)
{
	// テクスチャーを解放
	map<string, LPDIRECT3DTEXTURE9>::iterator it;
    for(it = textureMap.begin(); it != textureMap.end();)
	{
		it->second->Release();
		it = textureMap.erase(it);
	}
}

/*-------------------------------------------
	テクスチャの読み込み
--------------------------------------------*/
LPDIRECT3DTEXTURE9 DirectXLib::LoadTexture(const char *file_name)
{
	map<string, LPDIRECT3DTEXTURE9>::iterator it; // イテレータ
	it = textureMap.find(file_name); // 検索

	if (it != textureMap.end())
	{
		return it->second;
	}
	else
	{
		LPDIRECT3DTEXTURE9 texture = NULL;

		if(FAILED(D3DXCreateTextureFromFileEx(
			d3dDevice,
			file_name,						// ファイル名
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			1,
			0,
			D3DFMT_UNKNOWN,					// 色抜きを可能に
			D3DPOOL_MANAGED,
			D3DX_FILTER_BOX,
			D3DPOOL_DEFAULT,
			D3DCOLOR_XRGB(255, 0, 255),	// 赤紫色を透過色とする
			NULL,
			NULL,
			&texture						// テクスチャ名
		)))
		{
			char data[256];
			sprintf_s(data, "ファイル名 \"%s\"\nファイルの読み込みに失敗しました。", file_name);
			MessageBox(0, data, "Error!!", 0);

			return NULL;
		}
		else
		{
			textureMap.insert(pair<string, LPDIRECT3DTEXTURE9>(file_name, texture));
			return texture;
		}
	}

	/*
	// テクスチャの読み込み
    if(FAILED(D3DXCreateTextureFromFile(d3dDevice, file_name, &texture)))
	{
		char data[256];
		sprintf_s(data, "%sファイルの読み込みに失敗しました。", file_name);
		MessageBox(0, data, "Error!!", 0);

        return NULL;
	}
	*/
}

/*-------------------------------------------
	テクスチャの描画
--------------------------------------------*/
void DirectXLib::DrawTexture(LPDIRECT3DTEXTURE9 texture, int x, int y)
{
	sprite->Draw(texture, NULL, &D3DXVECTOR3(1.0f, 1.0f, 0.0f), &D3DXVECTOR3((float)x, (float)y, 0.0f), D3DCOLOR_RGBA(255, 255, 255, 255));
}

/*-------------------------------------------
	テクスチャの描画
--------------------------------------------*/
void DirectXLib::DrawTexture(LPDIRECT3DTEXTURE9 texture, int x, int y, RECT rect)
{
	sprite->Draw(texture, &rect, &D3DXVECTOR3(1.0f, 1.0f, 0.0f), &D3DXVECTOR3((float)x, (float)y, 0.0f), 0xffffffff);
}

/*-------------------------------------------
	テクスチャの描画
--------------------------------------------*/
void DirectXLib::DrawTexture(LPDIRECT3DTEXTURE9 texture, int x, int y, RECT rect, bool mirror)
{
	if (mirror)
	{
		sprite->Draw(texture, &rect, &D3DXVECTOR3(-1.0f, 1.0f, 0.0f), &D3DXVECTOR3((float)x + (rect.right - rect.left), (float)y, 0.0f), 0xffffffff);
	}
	else
	{
		sprite->Draw(texture, &rect, &D3DXVECTOR3(1.0f, 1.0f, 0.0f), &D3DXVECTOR3((float)x, (float)y, 0.0f), 0xffffffff);
	}
}


/*-------------------------------------------
	テクスチャの描画
--------------------------------------------*/
void DirectXLib::DrawTexture(LPDIRECT3DTEXTURE9 texture, int x, int y, int index)
{
	int sx = (int)(index % 16);
	int sy = (int)(index / 16);

	RECT rect = {sx * 16, sy * 16, (sx + 1) * 16, (sy + 1) * 16};
	sprite->Draw(texture, &rect, &D3DXVECTOR3(1.0f, 1.0f, 0.0f), &D3DXVECTOR3((float)x, (float)y, 0.0f), D3DCOLOR_RGBA(255, 255, 255, 255));
}

/*-------------------------------------------
	キーボード状態の取得
--------------------------------------------*/
bool DirectXLib::IsKeyDown(int key_no)
{
	if (keys[key_no] & 0x80)
	{
		return true;
	}

	return false;
}

/*-------------------------------------------
	ウィンドウ名を設定
--------------------------------------------*/
void DirectXLib::SetText(char* text)
{
	HWND hWnd = FindWindow("Rockman Casket", NULL);
	SetWindowText(hWnd, text);
}
