#pragma once

class GameLib
{
public:
	GameLib(void);
	virtual ~GameLib(void);

public:
	void DoMainLoop();

private:
	bool InitD3DWindow();		// Window + Direct3Dを初期化
	bool AppIdle();				// アイドル時の処理
	void GetKeyState();			// キーボード状態を取得

	virtual void Init() = 0;	// 初期化
	virtual void Move() = 0;	// ゲーム処理
	virtual void Render() = 0;	// 描画処理

private:
	HWND hWnd;						// ウィンドウハンドル
	LPDIRECT3D9 d3d;				// Direct3Dオブジェクト
	LPDIRECT3DDEVICE9 d3dDevice;	// Direct3Dデバイス
	D3DPRESENT_PARAMETERS d3dpp;	// Direct3D設定
	LPD3DXSPRITE sprite;			// Sprite
	LPDIRECTINPUT8 input;				// input
	LPDIRECTINPUTDEVICE8 inputDevice;	// inputデバイス
	DWORD lastTime;
};
