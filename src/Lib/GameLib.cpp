#include "StdAfx.h"
#include "GameLib.h"
#include <string>
#include <GameStateOperation.h>

// 初期ウィンドウサイズ
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// ウィンドウクラス名
const char* ClassName = "S-Type";

/*-------------------------------------------
	コンストラクタ
--------------------------------------------*/
GameLib::GameLib()
:hWnd(NULL),
d3d(NULL),
d3dDevice(NULL),
d3dpp(),
sprite(NULL),
input(NULL),
inputDevice(NULL),
lastTime(0),
windowWidth(WINDOW_WIDTH),
windowHeight(WINDOW_HEIGHT),
stateOperation(new GameStateOperation())
{
	
}

/*-------------------------------------------
	デストラクタ
--------------------------------------------*/
GameLib::~GameLib()
{
	if (inputDevice) inputDevice->Release();
	if (input) input->Release();
	if (sprite) sprite->Release();
	if (d3dDevice) d3dDevice->Release();
	if (d3d) d3d->Release();
	delete stateOperation;
}

/*-------------------------------------------
	FPS取得
--------------------------------------------*/
void GameLib::DrawFPS()
{
	// 1フレームにかかった時間.
	static DWORD beforTime = 0;
	static int frameCount = 0;
	static DWORD frameSum = 0;

	DWORD frameTime = timeGetTime() - beforTime;
	frameSum += frameTime;
	beforTime = timeGetTime();
	frameCount++;

	if (frameCount >= 10)
	{
		char title[256] = {};
		sprintf_s(title, "fps: %2.2f", ((1.0f / ((frameSum)) * 10000)));
		SetWindowText(hWnd, title);

		frameCount = 0;
		frameSum = 0;
	}
}

/*-------------------------------------------
	メインループ
--------------------------------------------*/
void GameLib::DoMainLoop()
{
	// 初期化
	if (InitD3DWindow() == false)
	{
		UnregisterClass(ClassName, GetModuleHandle(NULL));
		return;
	}

	// 初期化(各初期化)
	stateOperation->Init();

	// LastTime初期化
	lastTime = timeGetTime();

	// メッセージループ
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) // Windowsからメッセージを受け取る
		{
			TranslateMessage(&msg); // WM_KEYDOWN → WM_CHAR
			DispatchMessage(&msg); // ウィンドウプロシージャへイベントを送る
		}
		else
		{
			// FPS表示
			DrawFPS();

			// アイドル：ゲームメイン処理
			if (AppIdle() == false)
			{
				UnregisterClass(ClassName, GetModuleHandle(NULL));
				return;
			}
		}

		// 暴走を防ぐ
		Sleep(1);
	}

	UnregisterClass(ClassName, GetModuleHandle(NULL));
}

/*-------------------------------------------
	ゲームメイン処理（アイドル時）
--------------------------------------------*/
bool GameLib::AppIdle()
{
	// キーボードの状態を取得
	GetKeyState();

	// 移動
	stateOperation->Move();

	// 黒で塗りつぶして消去
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(255, 255, 255), 1.0, 0);

	// 描画開始
	if(SUCCEEDED(d3dDevice->BeginScene()))
	{
		if(SUCCEEDED(sprite->Begin(D3DXSPRITE_ALPHABLEND)))
		{
			// 描画
			stateOperation->Render();

			sprite->End();
		}
	}

	// 描画終了
	d3dDevice->EndScene();

	// 画面へ転送
	if(FAILED(d3dDevice->Present(NULL, NULL, NULL, NULL)))
	{
		if(FAILED(d3dDevice->Reset(&d3dpp)))
			return false;
	}

	// ループ時間を取得
	DWORD now = timeGetTime();
	float loopTime = (float)(now - lastTime) / 1000.0f;
	DirectXLib::SetLoopTime(loopTime);
	lastTime = now;

	return true;
}

/*-------------------------------------------
	ウィンドウプロシージャ
--------------------------------------------*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, UINT wParam, LONG lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0L;
}

/*-------------------------------------------
	Direct3D + Windowを初期化
--------------------------------------------*/
bool GameLib::InitD3DWindow()
{
	/*-------------------------------------------
		Windowを初期化
	--------------------------------------------*/
	// ウィンドウクラスの登録
	WNDCLASSEX wc;
	wc.cbSize 			= sizeof(WNDCLASSEX);
	wc.style			= CS_CLASSDC;
	wc.lpfnWndProc		= (WNDPROC)WndProc;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 0;
	wc.hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.hInstance		= GetModuleHandle(NULL);//hInst;
	wc.hIcon			= NULL;
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wc.lpszMenuName		= NULL;
	wc.lpszClassName	= ClassName;
	wc.hIconSm			= NULL;

	if(!RegisterClassEx(&wc))
		return false;

	// ウィンドウ作成
	int iWidth = WINDOW_WIDTH + GetSystemMetrics(SM_CXDLGFRAME) * 2;
	int iHeight = WINDOW_HEIGHT + GetSystemMetrics(SM_CYDLGFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION);

	hWnd = CreateWindowEx(0, ClassName, ClassName,
							WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX,
							CW_USEDEFAULT, CW_USEDEFAULT, iWidth, iHeight,
							(HWND)NULL, (HMENU)NULL,
							wc.hInstance, (LPSTR)NULL);
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);

	/*-------------------------------------------
		Direct3Dデバイスを作成
	--------------------------------------------*/
	// Direct3Dオブジェクトの取得
	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	if(d3d == NULL)
		return false;

	// ディスプレイモードを取得
	D3DDISPLAYMODE dsp;
	if (FAILED(d3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &dsp)))
		return false;

	// DirectX設定
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD; // 垂直同期でフリップ
	d3dpp.BackBufferFormat = dsp.Format; // ディスプレイのモードを設定
	d3dpp.Windowed = 1; // ウィンドウモード
	d3dpp.BackBufferWidth = WINDOW_WIDTH;
	d3dpp.BackBufferHeight = WINDOW_HEIGHT;
	d3dpp.BackBufferCount = 1;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;

	// デバイスを作成
	// T&L HAL
	if (FAILED(d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &d3dDevice)))
	{
		// HAL
		if (FAILED(d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3dDevice)))
		{
			// HEL
			if (FAILED(d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3dDevice)))
			{
				return false;
			}
		}
	}

	/*--------------------------------------------
		DirectXの機能を初期化
	---------------------------------------------*/
	// Sprite
	if (FAILED(D3DXCreateSprite(d3dDevice, &sprite)))
		return false;

	// Inputを初期化
	if (FAILED(DirectInput8Create(wc.hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&input, NULL)))
	{
		return false;
	}
	if (FAILED(input->CreateDevice(GUID_SysKeyboard, &inputDevice, NULL)))
	{
		return false;
	}
	inputDevice->SetDataFormat(&c_dfDIKeyboard);
	inputDevice->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	/*--------------------------------------------
		描画の設定など
	---------------------------------------------*/
	// アスペクト比を求める
	D3DVIEWPORT9 vp;
	d3dDevice->GetViewport(&vp);
	float fAspect = (float) vp.Width / (float) vp.Height;

	// 変換行列の設定
	D3DXMATRIX mat;
	D3DXMatrixPerspectiveFovLH(&mat, D3DXToRadian(45.0f), fAspect, 0.1f, 100.0f);
	d3dDevice->SetTransform(D3DTS_PROJECTION, &mat);
	D3DXMatrixLookAtLH(&mat, &D3DXVECTOR3(0.0f, 0.0f, -20.0f), &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 1, 0));
	d3dDevice->SetTransform(D3DTS_VIEW, &mat);

	// 描画設定
	d3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);	// カリングは行わない
	d3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);			// ライティングしない

	// 透過色(抜き色)を可能にする
	d3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);	//αブレンド可
	d3dDevice->SetRenderState(D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA);
	d3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	// 透過色(抜き色)の部分をZバッファに書き込まない
	d3dDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	d3dDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	d3dDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	// TODO DirectSoundを使用する
	/*
	IDirectSound8 *pDS8;
	DirectSoundCreate8(NULL, &pDS8, NULL);
	pDS8->SetCooperativeLevel(hWnd, DSSCL_NORMAL);
	*/

	/*--------------------------------------------
		DirectXLibへ渡す
	---------------------------------------------*/
	DirectXLib::Init(d3dDevice, sprite);

	return true;
}

/*--------------------------------------------
		キーボード状態を取得
---------------------------------------------*/
void GameLib::GetKeyState()
{
	HRESULT hr = inputDevice->Acquire();

	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		char keys[256];
		inputDevice->GetDeviceState(sizeof(keys), &keys);

		// DirectXLibへ渡す
		DirectXLib::SetKeyState(keys);
	}
}
