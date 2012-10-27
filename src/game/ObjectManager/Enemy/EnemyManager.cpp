#include "StdAfx.h"
#include "EnemyManager.h"
#include "EnemyObject.h"

/*-------------------------------------------
	�C���X�^���X�擾
--------------------------------------------*/
EnemyManager* EnemyManager::GetInstance()
{
	static EnemyManager instance;
	return &instance;
}

/*-------------------------------------------
	�R���X�g���N�^
--------------------------------------------*/
EnemyManager::EnemyManager()
:enemyList()
{
}

/*-------------------------------------------
	�f�X�g���N�^
--------------------------------------------*/
EnemyManager::~EnemyManager()
{
	// ���������
	for (std::list<EnemyObject*>::iterator it = enemyList.begin(); it != enemyList.end(); ++it)
	{
		delete (*it);
	}
	enemyList.clear();
}

/*-------------------------------------------
	�G�ǉ�
--------------------------------------------*/
void EnemyManager::AddEnemy(EnemyObject* enemy)
{
	enemyList.push_back(enemy);
}

/*-------------------------------------------
	������
--------------------------------------------*/
void EnemyManager::Init()
{
	for (std::list<EnemyObject*>::iterator it = enemyList.begin(); it != enemyList.end(); ++it)
	{
		(*it)->Init();
	}
}

/*-------------------------------------------
	�G����
--------------------------------------------*/
void EnemyManager::Move()
{
	for (std::list<EnemyObject*>::iterator it = enemyList.begin(); it != enemyList.end(); ++it)
	{
		(*it)->Move();
	}
}

/*-------------------------------------------
	�G�`��
--------------------------------------------*/
void EnemyManager::Draw()
{
	for (std::list<EnemyObject*>::iterator it = enemyList.begin(); it != enemyList.end(); ++it)
	{
		(*it)->Draw();
	}
}
