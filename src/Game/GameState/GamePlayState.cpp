#include "StdAfx.h"
#include "GamePlayState.h"
#include <ObjectManager/Enemy/EnemyManager.h>
#include <ObjectManager/Enemy/EnemyObject.h>
#include <ObjectManager/Stage/StageManager.h>
#include <ObjectManager/Bullet/BulletManager.h>

/*-------------------------------------------
	コンストラクタ
--------------------------------------------*/
GamePlayState::GamePlayState()
{
	stage = new Stage();
}

/*-------------------------------------------
	デストラクタ
--------------------------------------------*/
GamePlayState::~GamePlayState()
{
	delete stage;
}

/*-------------------------------------------
	初期化
--------------------------------------------*/
void GamePlayState::Init()
{
	// Stage音再生
	PlaySound("data/music/StgMusic.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	// TODO マップエディターから敵を追加する
	// TODO 画面内に敵が入った時に追加する
	for (long i = 0; i < 10; i++)
	{
		EnemyManager::GetInstance()->AddEnemy(OBJECT_ARAMAKI, 800+100*i, 0, 0);
	}

	// ショボンタワー
	for (long i = 0; i < 20; i++)
	{
		for (long j =0; j < 20; j++)
		{
			EnemyManager::GetInstance()->AddEnemy(OBJECT_SHOBON, 1500 + 150*j, 32*i, i%10);
		}
	}

	Boon::GetInstance()->Init();			// ブーン
	StageManager::GetInstance()->Move();	// ステージを右にスクロール
	EnemyManager::GetInstance()->Init();	// 敵
	BulletManager::GetInstance()->Init();	// 弾
}

/*-------------------------------------------
	オブジェクト同士の当たり判定
	objectA / objectBの当たり判定チェック
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
	移動
------------------------------------ --------*/
void GamePlayState::Move()
{
	Boon::GetInstance()->Move();			// ブーン
	StageManager::GetInstance()->Move();	// ステージを右にスクロール
	EnemyManager::GetInstance()->Move();	// 敵
	BulletManager::GetInstance()->Move();	// 弾

	// 当たり判定
	list<BulletObject*> bulletList = BulletManager::GetInstance()->GetObject();
	list<EnemyObject*> enemyList = EnemyManager::GetInstance()->GetObject();
	IObject *boonObject = Boon::GetInstance();

	for (std::list<EnemyObject*>::iterator ite = enemyList.begin(); ite != enemyList.end(); ++ite)
	{
		IObject *enemyObject = dynamic_cast<IObject*>(*ite);

		// 弾 & 敵当たり判定
		for (std::list<BulletObject*>::iterator itb = bulletList.begin(); itb != bulletList.end(); ++itb)
		{
			IObject *bulletObject = (IObject*)(*itb);

			// 当たり判定
			if (IsHit((*bulletObject), (*enemyObject)))
			{
				bulletObject->Hit();
				enemyObject->Hit();
			}
		}

		// ブーン & 敵当たり判定
		if (IsHit((*boonObject), (*enemyObject)))
		{
			boonObject->Hit();
		}
	}

	//boon->IsHit((*boon), enemyList.begin());

	//EnemyManager::GetInstance()->GetObject();

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
	Boon::GetInstance()->Draw();			// ブーン
	stage->Draw();							// ステージ
	EnemyManager::GetInstance()->Draw();	// 敵
	BulletManager::GetInstance()->Draw();	// 弾
}
