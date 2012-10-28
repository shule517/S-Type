#include "StdAfx.h"
#include "EnemyFactory.h"
#include "EnemyObject.h"

// �e���
#include "EnemyAramaki.h"
#include "EnemyShobonTower.h"

/*-------------------------------------------
	�R���X�g���N�^
--------------------------------------------*/
EnemyFactory::EnemyFactory()
{
}

/*-------------------------------------------
	�f�X�g���N�^
--------------------------------------------*/
EnemyFactory::~EnemyFactory()
{
}

/*-------------------------------------------
	�C���X�^���X����
--------------------------------------------*/
EnemyObject* EnemyFactory::Create(const E_OBJECT_TYPE objectType, const long x, const long y, const long animeNo)
{
	EnemyObject *enemy = NULL;

	// TODO �e�P�[�X���ŃI�u�W�F�N�g��ނɍ��킹�ēG����
	switch (objectType)
	{
	case OBJECT_ARAMAKI:	// �r��
		enemy = new EnemyAramaki(x, y, animeNo);
		break;
	case OBJECT_SHOBON:		// �V���{���^���[
		enemy = new EnemyShobonTower(x, y, animeNo);
		break;
	default:
		enemy = new EnemyAramaki(x, y, animeNo);
		break;
	}

	return enemy;
}
