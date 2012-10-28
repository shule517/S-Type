#include "StdAfx.h"
#include "BulletObject.h"

/*-------------------------------------------
	コンストラクタ
--------------------------------------------*/
BulletObject::BulletObject(const long x, const long y, const float dir)
:bulletDir(dir)
{
	posX = x;
	posY = y;
}

/*-------------------------------------------
	デストラクタ
--------------------------------------------*/
BulletObject::~BulletObject()
{
}
