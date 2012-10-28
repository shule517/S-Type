#include "StdAfx.h"
#include "StageManager.h"

/*-------------------------------------------
	インスタンス取得
--------------------------------------------*/
StageManager *StageManager::GetInstance()
{
	static StageManager instance;
	return &instance;
}

/*-------------------------------------------
	コンストラクタ
--------------------------------------------*/
StageManager::StageManager()
:stagePosX(0),
stagePosY(0)
{
}

/*-------------------------------------------
	デストラクタ
--------------------------------------------*/
StageManager::~StageManager()
{
}

/*-------------------------------------------
	ステージ表示位置設定
--------------------------------------------*/
void StageManager::SetStagePos(const long x, const long y)
{
	stagePosX = x;
	stagePosY = y;
}
/*-------------------------------------------
	ステージ表示位置取得
--------------------------------------------*/
D3DXVECTOR2 StageManager::GetStagePos()
{
	return D3DXVECTOR2(static_cast<float>(stagePosX), static_cast<float>(stagePosY));
}

/*-------------------------------------------
	ステージ移動
--------------------------------------------*/
void StageManager::Move()
{
	// 秒速100dotで右に移動
	float scrollSpeed = 100.0f;
	D3DXVECTOR2 stagePos = StageManager::GetInstance()->GetStagePos();
	float moveX = stagePos.x + DirectXLib::GetInstance()->GetMove(scrollSpeed);
	
	// 設定
	SetStagePos(moveX, stagePos.y);
}
