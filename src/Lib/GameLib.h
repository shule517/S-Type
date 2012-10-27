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
	bool InitD3DWindow();				// Window + Direct3D��������
	bool AppIdle();						// �A�C�h�����̏���
	void GetKeyState();					// �L�[�{�[�h��Ԃ��擾
	void DrawFPS();						// FPS�\��

private:
	HWND hWnd;							// �E�B���h�E�n���h��
	LPDIRECT3D9 d3d;					// Direct3D�I�u�W�F�N�g
	LPDIRECT3DDEVICE9 d3dDevice;		// Direct3D�f�o�C�X
	D3DPRESENT_PARAMETERS d3dpp;		// Direct3D�ݒ�
	LPD3DXSPRITE sprite;				// Sprite
	LPDIRECTINPUT8 input;				// input
	LPDIRECTINPUTDEVICE8 inputDevice;	// input�f�o�C�X
	DWORD lastTime;
	long windowHeight;					// �E�B���h�E����
	long windowWidth;					// �E�B���h�E��
	GameStateOperation * stateOperation;// ��ԑ���
};
