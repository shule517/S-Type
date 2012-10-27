#include "StdAfx.h"
#include "DirectXLib.h"

// C4351(�����o�C�j�V�����C�U�ł̔z�񏉊����F���ɖ��Ȃ�)
#pragma warning(disable:4351)

/*-------------------------------------------
	�C���X�^���X�擾
--------------------------------------------*/
DirectXLib* DirectXLib::GetInstance()
{
	static DirectXLib instance;
	return &instance;
}

/*-------------------------------------------
	�R���X�g���N�^
--------------------------------------------*/
DirectXLib::DirectXLib()
:d3dDevice(NULL),
sprite(NULL),
keys(),
loopTime(0),
textureMap(),
d3dLine(NULL)
{
	D3DXCreateLine(d3dDevice, &d3dLine);
}

/*-------------------------------------------
	�f�X�g���N�^
--------------------------------------------*/
DirectXLib::~DirectXLib()
{
	// �e�N�X�`���[�����
	map<string, LPDIRECT3DTEXTURE9>::iterator it;
    for(it = textureMap.begin(); it != textureMap.end();)
	{
		it->second->Release();
		it = textureMap.erase(it);
	}
}

/*-------------------------------------------
	������
--------------------------------------------*/
void DirectXLib::Init(LPDIRECT3DDEVICE9 _d3dDevice, LPD3DXSPRITE _sprite)
{
	d3dDevice = _d3dDevice;
	sprite = _sprite;
}

/*-------------------------------------------
	�L�[�{�[�h���͏�Ԃ̐ݒ�
--------------------------------------------*/
void DirectXLib::SetKeyState(char *_keys)
{
	for (int i = 0; i < 256; i++)
	{
		keys[i] = _keys[i];
	}
}

/*-------------------------------------------
	���[�v�^�C��(1���[�v�ɂ�����������)��ݒ�
--------------------------------------------*/
void DirectXLib::SetLoopTime(float time)
{
	loopTime = time;
}

/*-------------------------------------------
	�e�N�X�`���̓ǂݍ���
--------------------------------------------*/
LPDIRECT3DTEXTURE9 DirectXLib::LoadTexture(const char *file_name)
{
	map<string, LPDIRECT3DTEXTURE9>::iterator it; // �C�e���[�^
	it = textureMap.find(file_name); // ����

	if (it != textureMap.end())
	{
		return it->second;
	}
	else
	{
		LPDIRECT3DTEXTURE9 texture = NULL;

		if(FAILED(D3DXCreateTextureFromFileEx(
			d3dDevice,
			file_name,						// �t�@�C����
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			1,
			0,
			D3DFMT_UNKNOWN,					// �F�������\��
			D3DPOOL_MANAGED,
			D3DX_FILTER_BOX,
			D3DPOOL_DEFAULT,
			D3DCOLOR_XRGB(255, 0, 255),	// �Ԏ��F�𓧉ߐF�Ƃ���
			NULL,
			NULL,
			&texture						// �e�N�X�`����
		)))
		{
			char data[256];
			sprintf_s(data, "�t�@�C���� \"%s\"\n�t�@�C���̓ǂݍ��݂Ɏ��s���܂����B", file_name);
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
	// �e�N�X�`���̓ǂݍ���
    if(FAILED(D3DXCreateTextureFromFile(d3dDevice, file_name, &texture)))
	{
		char data[256];
		sprintf_s(data, "%s�t�@�C���̓ǂݍ��݂Ɏ��s���܂����B", file_name);
		MessageBox(0, data, "Error!!", 0);

        return NULL;
	}
	*/
}

/*-------------------------------------------
	�e�N�X�`���̕`��
--------------------------------------------*/
void DirectXLib::DrawTexture(LPDIRECT3DTEXTURE9 texture, int x, int y)
{
	sprite->Draw(texture, NULL, &D3DXVECTOR3(1.0f, 1.0f, 0.0f), &D3DXVECTOR3((float)x, (float)y, 0.0f), D3DCOLOR_RGBA(255, 255, 255, 255));
}

/*-------------------------------------------
	�e�N�X�`���̕`��
--------------------------------------------*/
void DirectXLib::DrawTexture(LPDIRECT3DTEXTURE9 texture, int x, int y, RECT rect)
{
	sprite->Draw(texture, &rect, &D3DXVECTOR3(1.0f, 1.0f, 0.0f), &D3DXVECTOR3((float)x, (float)y, 0.0f), 0xffffffff);
}

/*-------------------------------------------
	�e�N�X�`���̕`��	
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
	�l�p�`�̕`��
	��������
	startPos: �l�p�`�̎n�_�i������W�j
	endPos: �l�p�`�̏I�_�i�E�����W�j
--------------------------------------------*/
void DirectXLib::DrawBox(D3DXVECTOR2 startPos, D3DXVECTOR2 endPos)
{
	// 4�_�F�l�p�`�`��
	const short vertexCount = 4;
	D3DXVECTOR2 vec[vertexCount] = { startPos, D3DXVECTOR2(startPos.x, endPos.y), endPos, D3DXVECTOR2(endPos.x, startPos.y) };
	d3dLine->Begin();
	d3dLine->Draw(vec, vertexCount, D3DCOLOR_ARGB(255, 255, 0, 0));
	d3dLine->End();
}

/*-------------------------------------------
	�����̕`��
	��������
	startPos: �����̎n�_
	endPos: �����̏I�_
--------------------------------------------*/
void DirectXLib::DrawLine(D3DXVECTOR2 startPos, D3DXVECTOR2 endPos)
{
	// 2�_�F�����`��
	const short vertexCount = 2;
	D3DXVECTOR2 vec[vertexCount] = { startPos, endPos };
	d3dLine->Begin();
	d3dLine->Draw(vec, vertexCount, D3DCOLOR_ARGB(255, 255, 0, 0));
	d3dLine->End();
}

/*-------------------------------------------
	�e�N�X�`���̕`��
--------------------------------------------*/
void DirectXLib::DrawTexture(LPDIRECT3DTEXTURE9 texture, int x, int y, int index)
{
	int sx = (int)(index % 16);
	int sy = (int)(index / 16);

	RECT rect = {sx * 16, sy * 16, (sx + 1) * 16, (sy + 1) * 16};
	sprite->Draw(texture, &rect, &D3DXVECTOR3(1.0f, 1.0f, 0.0f), &D3DXVECTOR3((float)x, (float)y, 0.0f), D3DCOLOR_RGBA(255, 255, 255, 255));
}

/*-------------------------------------------
	�L�[�{�[�h��Ԃ̎擾
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
	�E�B���h�E����ݒ�
--------------------------------------------*/
void DirectXLib::SetText(char* text)
{
	HWND hWnd = FindWindow("S-Type", NULL);
	SetWindowText(hWnd, text);
}
