#pragma once

#include <list>
#include "../E_OBJECT_TYPE.h"

class EnemyFactory;
class EnemyObject;
class EnemyManager
{
public:
	static EnemyManager* GetInstance();

	void AddEnemy(const E_OBJECT_TYPE objectType, const long x, const long y, const long animeNo);
	const list<EnemyObject*>& GetObject(){ return enemyList; }

	void Init();
	void Move();
	void Draw();

private:
	EnemyManager();
	virtual ~EnemyManager();

private:
	EnemyFactory* enemyFactory;		// ìGê∂ê¨
	list<EnemyObject*> enemyList;	// ìGÉäÉXÉg
};
