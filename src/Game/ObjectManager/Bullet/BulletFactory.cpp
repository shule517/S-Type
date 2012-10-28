#include "StdAfx.h"
#include "BulletFactory.h"
#include "BulletObject.h"

// �e���
#include "BulletStandard.h"
#include "BulletMissile.h"

/*-------------------------------------------
	�R���X�g���N�^
--------------------------------------------*/
BulletFactory::BulletFactory()
{
}

/*-------------------------------------------
	�f�X�g���N�^
--------------------------------------------*/
BulletFactory::~BulletFactory()
{
}

/*-------------------------------------------
	�C���X�^���X����
--------------------------------------------*/
BulletObject* BulletFactory::Create(const E_OBJECT_TYPE objectType, const long x, const long y, const float dir)
{
	BulletObject *bullet = NULL;

	// TODO �e�P�[�X���ŃI�u�W�F�N�g��ނɍ��킹�Ēe����
	switch (objectType)
	{
	case OBJECT_BULLET_STANDARD:	// �W���e
		bullet = new BulletStandard(x, y, dir);
		break;

	case OBJECT_BULLET_MISSILE:		// �~�T�C��
		bullet = new BulletMissile(x, y, dir);
		break;

	default:						// �W���e
		bullet = new BulletStandard(x, y, dir);
		break;
	}

	// ������
	bullet->Init();

	return bullet;
}
