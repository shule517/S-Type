#pragma once

#include <list>

class EnemyObject;
class EnemyManager
{
public:
	static EnemyManager* GetInstance();

	void AddEnemy(EnemyObject* enemy);
	const list<EnemyObject*>& GetObject(){ return enemyList; }

	void Init();
	void Move();
	void Draw();

private:
	EnemyManager();
	virtual ~EnemyManager();

private:
	list<EnemyObject*> enemyList;	// “GƒŠƒXƒg
};
