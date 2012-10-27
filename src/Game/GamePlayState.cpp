#include "StdAfx.h"
#include "GamePlayState.h"

/*-------------------------------------------
	�R���X�g���N�^
--------------------------------------------*/
GamePlayState::GamePlayState()
{
	stage = new Stage();
	boon = new Boon();
}

/*-------------------------------------------
	�f�X�g���N�^
--------------------------------------------*/
GamePlayState::~GamePlayState()
{
	delete stage;
	delete boon;
}

/*-------------------------------------------
	������
--------------------------------------------*/
void GamePlayState::Init()
{
	stage->Init();
	boon->Init();
}

/*-------------------------------------------
	�ړ�
--------------------------------------------*/
void GamePlayState::Move()
{
	boon->Move();
	/*
	// TODO �ȉ��A������
	// �e���ړ�
	stage->Move();
	boon->Move();
	boonBullet->Move();
	enemy->Move();			// ���@�Ɍ������Ĉړ������������@�ʒu���ق���
	enemyBullet->Move();
	force->Move();			// ���@�Ƃ��������ꍇ�Ɂ����@�ʒu���ق���

	// stage�̒��ɁA�n�`�f�[�^�������L��
	Object stageObject[] = stage->GetObject();
	Object boonObject[] = stage->GetObject();
	Object enemyObject[] = stage->GetObject();
	Object enemyBulletObject[] = stage->GetObject();
	Object forceObject[] = stage->GetObject();

	//***********************
	// �����蔻��
	//***********************

	// ���@�Ƃ̓����蔻��
	isHitObjectArray(boon, force);		// �t�H�[�X * 1
	isHitObjectArray(boon, enemy);		// �G * 30
	isHitObjectArray(boon, stage);		// �n�` * 30

	// ���@�e�Ƃ̓����蔻��
	isHitObjectArray(boonBullet, enemy)	// �G 30*5 150

	// �G�Ƃ̓����蔻��
	isHitObject(enemy, stage);			// �n�` * 30 = 90

void isHitObjectArray(list<Object*> A, list<Object*> B)
{
	// �����蔻����s
	for (long i = 0; i < mapObject.length; i++)
	{
		for (long j = 0; j < boonObject.length; j++)
		{
			bool isHit = isHitCheck(mapObject, boonObject)
			if (isHit)
			{
				mapObject->Hit(boonObject);
				boonObject->Hit(mapObject);
			}
		}
	}
}


	// �����͓�����������
	Boon::Hit(Object object)
	{
		// �G�e�ɂ�������
		if (object.type == enemyBullet)
		{
			Damege();
		}
		// �G�ɂ�������
		else if(object.type == enemy)
		{
			Damege();
		}
		// �t�H�[�X�ɂ�������
		else if(object.type == force)
		{
			object.
		}
	}

	Force::Hit(Object object)
	{
		if (object.type == boon)
		{
			// �u�[���ɍ���
			Fusion();
		}
	}

	Force::Fusion(E_POS)
	{
		if (E_POS == front)
		{
			// �O�ɂ�������
		}
		else if (E_POS == back)
		{
			// ���ɂ�������
		}
		
		// �������܂���
		fusionFlag = true;
	}

	Force::Move()
	{
		if (fusionFlag)
		{
			this->x = boon.x + 30;
		}
	}


	boon->Move();
	*/

	// �����蔻����s

	// ���@�ƓG�L�������Ԃ�������
	// ���@�ƒn�`���Ԃ�������
	// ���@�e�ƓG�L�������Ԃ�������

	// �G�L�����ƒn�`���Ԃ�������
}

/*-------------------------------------------
	�`��
--------------------------------------------*/
void GamePlayState::Render()
{
	stage->Draw();
	boon->Draw();
}
