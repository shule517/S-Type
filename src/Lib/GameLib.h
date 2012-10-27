#pragma once

class GameStateOperation;
class GameLib
{
public:
	GameLib();
	virtual ~GameLib();

public:
	void DoMainLoop();

private:
	bool InitD3DWindow();				// Window + Direct3Dを初期化
	bool AppIdle();						// アイドル時の処理
	void GetKeyState();					// キーボード状態を取得
	void DrawFPS();						// FPS表示

private:
	HWND hWnd;							// ウィンドウハンドル
	LPDIRECT3D9 d3d;					// Direct3Dオブジェクト
	LPDIRECT3DDEVICE9 d3dDevice;		// Direct3Dデバイス
	D3DPRESENT_PARAMETERS d3dpp;		// Direct3D設定
	LPD3DXSPRITE sprite;				// Sprite
	LPDIRECTINPUT8 input;				// input
	LPDIRECTINPUTDEVICE8 inputDevice;	// inputデバイス
	DWORD lastTime;
	long windowHeight;					// ウィンドウ高さ
	long windowWidth;					// ウィンドウ幅
	GameStateOperation * stateOperation;// 状態操作
};
