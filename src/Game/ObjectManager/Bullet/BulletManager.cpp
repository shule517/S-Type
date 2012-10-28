#include "StdAfx.h"
#include "BulletManager.h"
#include "BulletFactory.h"
#include "BulletObject.h"

/*-------------------------------------------
	�C���X�^���X�擾
--------------------------------------------*/
BulletManager* BulletManager::GetInstance()
{
	static BulletManager instance;
	return &instance;
}

/*-------------------------------------------
	�R���X�g���N�^
--------------------------------------------*/
BulletManager::BulletManager()
:bulletList(),
bulletFactory(new BulletFactory())
{
}

/*-------------------------------------------
	�f�X�g���N�^
--------------------------------------------*/
BulletManager::~BulletManager()
{
	delete bulletFactory;

	// ���������
	for (std::list<BulletObject*>::iterator it = bulletList.begin(); it != bulletList.end(); ++it)
	{
		delete (*it);
	}
	bulletList.clear();
}

/*-------------------------------------------
	�e�����i�e��ǉ��j
--------------------------------------------*/
void BulletManager::ShootBullet(E_OBJECT_TYPE objectType, float x, float y, float dir)
{
	// �t�@�N�g���[�œG����
	BulletObject *bullet = bulletFactory->Create(objectType, x, y, dir);
	bulletList.push_back(bullet);
}

/*-------------------------------------------
	������
--------------------------------------------*/
void BulletManager::Init()
{
	for (std::list<BulletObject*>::iterator it = bulletList.begin(); it != bulletList.end(); ++it)
	{
		(*it)->Init();
	}
}

/*-------------------------------------------
	�G����
--------------------------------------------*/
void BulletManager::Move()
{
	for (std::list<BulletObject*>::iterator it = bulletList.begin(); it != bulletList.end(); ++it)
	{
		(*it)->Move();
	}
}

/*-------------------------------------------
	�G�`��
--------------------------------------------*/
void BulletManager::Draw()
{
	for (std::list<BulletObject*>::iterator it = bulletList.begin(); it != bulletList.end(); ++it)
	{
		(*it)->Draw();
	}
}
