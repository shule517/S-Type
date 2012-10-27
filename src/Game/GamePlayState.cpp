#include "StdAfx.h"
#include "GamePlayState.h"

/*-------------------------------------------
	コンストラクタ
--------------------------------------------*/
GamePlayState::GamePlayState()
{
	stage = new Stage();
	boon = new Boon();
}

/*-------------------------------------------
	デストラクタ
--------------------------------------------*/
GamePlayState::~GamePlayState()
{
	delete stage;
	delete boon;
}

/*-------------------------------------------
	初期化
--------------------------------------------*/
void GamePlayState::Init()
{
	stage->Init();
	boon->Init();
}

/*-------------------------------------------
	移動
--------------------------------------------*/
void GamePlayState::Move()
{
	boon->Move();
	/*
	// TODO 以下、実装案
	// 各自移動
	stage->Move();
	boon->Move();
	boonBullet->Move();
	enemy->Move();			// 自機に向かって移動したい→自機位置がほしい
	enemyBullet->Move();
	force->Move();			// 自機とくっついた場合に→自機位置がほしい

	// stageの中に、地形データが複数有る
	Object stageObject[] = stage->GetObject();
	Object boonObject[] = stage->GetObject();
	Object enemyObject[] = stage->GetObject();
	Object enemyBulletObject[] = stage->GetObject();
	Object forceObject[] = stage->GetObject();

	//***********************
	// 当たり判定
	//***********************

	// 自機との当たり判定
	isHitObjectArray(boon, force);		// フォース * 1
	isHitObjectArray(boon, enemy);		// 敵 * 30
	isHitObjectArray(boon, stage);		// 地形 * 30

	// 自機弾との当たり判定
	isHitObjectArray(boonBullet, enemy)	// 敵 30*5 150

	// 敵との当たり判定
	isHitObject(enemy, stage);			// 地形 * 30 = 90

void isHitObjectArray(list<Object*> A, list<Object*> B)
{
	// 当たり判定実行
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


	// 引数は当たった相手
	Boon::Hit(Object object)
	{
		// 敵弾にあたった
		if (object.type == enemyBullet)
		{
			Damege();
		}
		// 敵にあたった
		else if(object.type == enemy)
		{
			Damege();
		}
		// フォースにあたった
		else if(object.type == force)
		{
			object.
		}
	}

	Force::Hit(Object object)
	{
		if (object.type == boon)
		{
			// ブーンに合体
			Fusion();
		}
	}

	Force::Fusion(E_POS)
	{
		if (E_POS == front)
		{
			// 前にくっついた
		}
		else if (E_POS == back)
		{
			// 後ろにくっついた
		}
		
		// くっつきました
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

	// 当たり判定実行

	// 自機と敵キャラがぶつかったか
	// 自機と地形がぶつかったか
	// 自機弾と敵キャラがぶつかったか

	// 敵キャラと地形がぶつかったか
}

/*-------------------------------------------
	描画
--------------------------------------------*/
void GamePlayState::Render()
{
	stage->Draw();
	boon->Draw();
}
