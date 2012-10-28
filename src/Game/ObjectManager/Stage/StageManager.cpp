#include "StdAfx.h"
#include "StageManager.h"

/*-------------------------------------------
	�C���X�^���X�擾
--------------------------------------------*/
StageManager *StageManager::GetInstance()
{
	static StageManager instance;
	return &instance;
}

/*-------------------------------------------
	�R���X�g���N�^
--------------------------------------------*/
StageManager::StageManager()
:stagePosX(0),
stagePosY(0)
{
}

/*-------------------------------------------
	�f�X�g���N�^
--------------------------------------------*/
StageManager::~StageManager()
{
}

/*-------------------------------------------
	�X�e�[�W�\���ʒu�ݒ�
--------------------------------------------*/
void StageManager::SetStagePos(const long x, const long y)
{
	stagePosX = x;
	stagePosY = y;
}
/*-------------------------------------------
	�X�e�[�W�\���ʒu�擾
--------------------------------------------*/
D3DXVECTOR2 StageManager::GetStagePos()
{
	return D3DXVECTOR2(static_cast<float>(stagePosX), static_cast<float>(stagePosY));
}

/*-------------------------------------------
	�X�e�[�W�ړ�
--------------------------------------------*/
void StageManager::Move()
{
	// �b��100dot�ŉE�Ɉړ�
	float scrollSpeed = 100.0f;
	D3DXVECTOR2 stagePos = StageManager::GetInstance()->GetStagePos();
	float moveX = stagePos.x + DirectXLib::GetInstance()->GetMove(scrollSpeed);
	
	// �ݒ�
	SetStagePos(moveX, stagePos.y);
}
