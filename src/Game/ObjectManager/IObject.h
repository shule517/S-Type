#pragma once

#include "Stage/StageManager.h"

class IObject
{
public:
	IObject()
	:posX(0),
	posY(0),
	imageWidth(32),		// TODO XML����f�[�^�擾����
	imageHeight(32),	// TODO XML����f�[�^�擾���� 
	boundsWidth(32),	// TODO XML����f�[�^�擾����
	boundsHeight(32),	// TODO XML����f�[�^�擾����
	startAnimeNo(0),	// TODO XML����f�[�^�擾����
	life(1)				// TODO XML����f�[�^�擾����
	{};
	virtual ~IObject(){};

	virtual void Init()= 0;	// ������
	virtual void Move()= 0;	// �ړ�
	virtual void Draw()= 0;	// �`��
	virtual void Hit(){};	// �Ԃ�����

	// �\���ʒu���擾
	D3DXVECTOR2 GetClientPos()
	{
		// �X�e�[�W���W���擾
		D3DXVECTOR2 stagePos = StageManager::GetInstance()->GetStagePos();

		// �\���ʒu(Client���W)��Ԃ�
		return D3DXVECTOR2(posX - stagePos.x, posY - stagePos.y);
	}

// �{���́uprotected�v
	long posX;				// X���W
	long posY;				// Y���W
	long imageWidth;		// �摜��
	long imageHeight;		// �摜����
	long boundsWidth;		// �����蔻��(��)
	long boundsHeight;		// �����蔻��(����)
	long startAnimeNo;		// �J�n�A�j��No
	long life;				// ���C�t
};
