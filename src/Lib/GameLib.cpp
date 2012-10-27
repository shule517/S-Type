#include "StdAfx.h"
#include "GameLib.h"
#include <string>
#include <GameStateOperation.h>

// �����E�B���h�E�T�C�Y
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// �E�B���h�E�N���X��
const char* ClassName = "S-Type";

/*-------------------------------------------
	�R���X�g���N�^
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
	�f�X�g���N�^
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
	FPS�擾
--------------------------------------------*/
void GameLib::DrawFPS()
{
	// 1�t���[���ɂ�����������.
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
	���C�����[�v
--------------------------------------------*/
void GameLib::DoMainLoop()
{
	// ������
	if (InitD3DWindow() == false)
	{
		UnregisterClass(ClassName, GetModuleHandle(NULL));
		return;
	}

	// ������(�e������)
	stateOperation->Init();

	// LastTime������
	lastTime = timeGetTime();

	// ���b�Z�[�W���[�v
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) // Windows���烁�b�Z�[�W���󂯎��
		{
			TranslateMessage(&msg); // WM_KEYDOWN �� WM_CHAR
			DispatchMessage(&msg); // �E�B���h�E�v���V�[�W���փC�x���g�𑗂�
		}
		else
		{
			// FPS�\��
			DrawFPS();

			// �A�C�h���F�Q�[�����C������
			if (AppIdle() == false)
			{
				UnregisterClass(ClassName, GetModuleHandle(NULL));
				return;
			}
		}

		// �\����h��
		Sleep(1);
	}

	UnregisterClass(ClassName, GetModuleHandle(NULL));
}

/*-------------------------------------------
	�Q�[�����C�������i�A�C�h�����j
--------------------------------------------*/
bool GameLib::AppIdle()
{
	// �L�[�{�[�h�̏�Ԃ��擾
	GetKeyState();

	// �ړ�
	stateOperation->Move();

	// ���œh��Ԃ��ď���
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(255, 255, 255), 1.0, 0);

	// �`��J�n
	if(SUCCEEDED(d3dDevice->BeginScene()))
	{
		if(SUCCEEDED(sprite->Begin(D3DXSPRITE_ALPHABLEND)))
		{
			// �`��
			stateOperation->Render();

			sprite->End();
		}
	}

	// �`��I��
	d3dDevice->EndScene();

	// ��ʂ֓]��
	if(FAILED(d3dDevice->Present(NULL, NULL, NULL, NULL)))
	{
		if(FAILED(d3dDevice->Reset(&d3dpp)))
			return false;
	}

	// ���[�v���Ԃ��擾
	DWORD now = timeGetTime();
	float loopTime = (float)(now - lastTime) / 1000.0f;
	DirectXLib::SetLoopTime(loopTime);
	lastTime = now;

	return true;
}

/*-------------------------------------------
	�E�B���h�E�v���V�[�W��
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
	Direct3D + Window��������
--------------------------------------------*/
bool GameLib::InitD3DWindow()
{
	/*-------------------------------------------
		Window��������
	--------------------------------------------*/
	// �E�B���h�E�N���X�̓o�^
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

	// �E�B���h�E�쐬
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
		Direct3D�f�o�C�X���쐬
	--------------------------------------------*/
	// Direct3D�I�u�W�F�N�g�̎擾
	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	if(d3d == NULL)
		return false;

	// �f�B�X�v���C���[�h���擾
	D3DDISPLAYMODE dsp;
	if (FAILED(d3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &dsp)))
		return false;

	// DirectX�ݒ�
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD; // ���������Ńt���b�v
	d3dpp.BackBufferFormat = dsp.Format; // �f�B�X�v���C�̃��[�h��ݒ�
	d3dpp.Windowed = 1; // �E�B���h�E���[�h
	d3dpp.BackBufferWidth = WINDOW_WIDTH;
	d3dpp.BackBufferHeight = WINDOW_HEIGHT;
	d3dpp.BackBufferCount = 1;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;

	// �f�o�C�X���쐬
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
		DirectX�̋@�\��������
	---------------------------------------------*/
	// Sprite
	if (FAILED(D3DXCreateSprite(d3dDevice, &sprite)))
		return false;

	// Input��������
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
		�`��̐ݒ�Ȃ�
	---------------------------------------------*/
	// �A�X�y�N�g������߂�
	D3DVIEWPORT9 vp;
	d3dDevice->GetViewport(&vp);
	float fAspect = (float) vp.Width / (float) vp.Height;

	// �ϊ��s��̐ݒ�
	D3DXMATRIX mat;
	D3DXMatrixPerspectiveFovLH(&mat, D3DXToRadian(45.0f), fAspect, 0.1f, 100.0f);
	d3dDevice->SetTransform(D3DTS_PROJECTION, &mat);
	D3DXMatrixLookAtLH(&mat, &D3DXVECTOR3(0.0f, 0.0f, -20.0f), &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 1, 0));
	d3dDevice->SetTransform(D3DTS_VIEW, &mat);

	// �`��ݒ�
	d3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);	// �J�����O�͍s��Ȃ�
	d3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);			// ���C�e�B���O���Ȃ�

	// ���ߐF(�����F)���\�ɂ���
	d3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);	//���u�����h��
	d3dDevice->SetRenderState(D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA);
	d3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	// ���ߐF(�����F)�̕�����Z�o�b�t�@�ɏ������܂Ȃ�
	d3dDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	d3dDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	d3dDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	// TODO DirectSound���g�p����
	/*
	IDirectSound8 *pDS8;
	DirectSoundCreate8(NULL, &pDS8, NULL);
	pDS8->SetCooperativeLevel(hWnd, DSSCL_NORMAL);
	*/

	/*--------------------------------------------
		DirectXLib�֓n��
	---------------------------------------------*/
	DirectXLib::Init(d3dDevice, sprite);

	return true;
}

/*--------------------------------------------
		�L�[�{�[�h��Ԃ��擾
---------------------------------------------*/
void GameLib::GetKeyState()
{
	HRESULT hr = inputDevice->Acquire();

	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		char keys[256];
		inputDevice->GetDeviceState(sizeof(keys), &keys);

		// DirectXLib�֓n��
		DirectXLib::SetKeyState(keys);
	}
}
