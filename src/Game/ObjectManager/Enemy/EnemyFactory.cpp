#include "StdAfx.h"
#include "EnemyFactory.h"
#include "EnemyObject.h"

EnemyFactory::EnemyFactory()
{
}

EnemyFactory::~EnemyFactory()
{
}

EnemyObject* EnemyFactory::Create(const E_OBJECT_TYPE objectType, const long x, const long y)
{
	EnemyObject *enemy = NULL;

	// TODO �e�P�[�X���ŃI�u�W�F�N�g��ނɍ��킹�ēG����
	switch (objectType)
	{
	case OBJECT_ARAMAKI:	// �r��
		enemy = new EnemyObject(x, y);
		break;
	case OBJECT_SHOBON:		// �V���{���^���[
		enemy = new EnemyObject(x, y);
		break;
	default:
		enemy = new EnemyObject(x, y);
		break;
	}

	return enemy;
}
