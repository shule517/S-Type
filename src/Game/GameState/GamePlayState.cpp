#include "StdAfx.h"
#include "GamePlayState.h"
#include <ObjectManager/Enemy/EnemyManager.h>
#include <ObjectManager/Enemy/EnemyObject.h>
#include <ObjectManager/Stage/StageManager.h>
#include <ObjectManager/Bullet/BulletManager.h>

/*-------------------------------------------
	�R���X�g���N�^
--------------------------------------------*/
GamePlayState::GamePlayState()
{
	stage = new Stage();
}

/*-------------------------------------------
	�f�X�g���N�^
--------------------------------------------*/
GamePlayState::~GamePlayState()
{
	delete stage;
}

/*-------------------------------------------
	������
--------------------------------------------*/
void GamePlayState::Init()
{
	// Stage���Đ�
	PlaySound("data/music/StgMusic.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	// TODO �}�b�v�G�f�B�^�[����G��ǉ�����
	// TODO ��ʓ��ɓG�����������ɒǉ�����
	for (long i = 0; i < 10; i++)
	{
		EnemyManager::GetInstance()->AddEnemy(OBJECT_ARAMAKI, 800+100*i, 0, 0);
	}

	// �V���{���^���[
	for (long i = 0; i < 20; i++)
	{
		for (long j =0; j < 20; j++)
		{
			EnemyManager::GetInstance()->AddEnemy(OBJECT_SHOBON, 1500 + 150*j, 32*i, i%10);
		}
	}

	Boon::GetInstance()->Init();			// �u�[��
	StageManager::GetInstance()->Move();	// �X�e�[�W���E�ɃX�N���[��
	EnemyManager::GetInstance()->Init();	// �G
	BulletManager::GetInstance()->Init();	// �e
}

/*-------------------------------------------
	�I�u�W�F�N�g���m�̓����蔻��
	objectA / objectB�̓����蔻��`�F�b�N
--------------------------------------------*/
bool IsHit(const IObject& a, const IObject& b)
{
	long ax1 = a.posX + (a.imageWidth  - a.boundsWidth) / 2;
	long ay1 = a.posY + (a.imageHeight - a.imageHeight) / 2;
	long ax2 = a.posX + (a.imageWidth  + a.boundsWidth) / 2;
	long ay2 = a.posY + (a.imageHeight + a.imageHeight) / 2;
	long bx1 = b.posX + (b.imageWidth  - b.boundsWidth) / 2;
	long by1 = b.posY + (b.imageHeight - b.imageHeight) / 2;
	long bx2 = b.posX + (b.imageWidth  + b.boundsWidth) / 2;
	long by2 = b.posY + (b.imageHeight + b.imageHeight) / 2;
	
	if ((ax1 < bx2) &&
		(bx1 < ax2) &&
		(ay1 < by2) &&
		(by1 < ay2))
	{
		return true;
	}
	
	return false;
}

/*-------------------------------------------
	�ړ�
------------------------------------ --------*/
void GamePlayState::Move()
{
	Boon::GetInstance()->Move();			// �u�[��
	StageManager::GetInstance()->Move();	// �X�e�[�W���E�ɃX�N���[��
	EnemyManager::GetInstance()->Move();	// �G
	BulletManager::GetInstance()->Move();	// �e

	// �����蔻��
	list<BulletObject*> bulletList = BulletManager::GetInstance()->GetObject();
	list<EnemyObject*> enemyList = EnemyManager::GetInstance()->GetObject();
	IObject *boonObject = Boon::GetInstance();

	for (std::list<EnemyObject*>::iterator ite = enemyList.begin(); ite != enemyList.end(); ++ite)
	{
		IObject *enemyObject = dynamic_cast<IObject*>(*ite);

		// �e & �G�����蔻��
		for (std::list<BulletObject*>::iterator itb = bulletList.begin(); itb != bulletList.end(); ++itb)
		{
			IObject *bulletObject = (IObject*)(*itb);

			// �����蔻��
			if (IsHit((*bulletObject), (*enemyObject)))
			{
				bulletObject->Hit();
				enemyObject->Hit();
			}
		}

		// �u�[�� & �G�����蔻��
		if (IsHit((*boonObject), (*enemyObject)))
		{
			boonObject->Hit();
		}
	}

	//boon->IsHit((*boon), enemyList.begin());

	//EnemyManager::GetInstance()->GetObject();

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
	Boon::GetInstance()->Draw();			// �u�[��
	stage->Draw();							// �X�e�[�W
	EnemyManager::GetInstance()->Draw();	// �G
	BulletManager::GetInstance()->Draw();	// �e
}
