#include "StdAfx.h"
#include "Stage.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Init()
{
	texture = DirectXLib::GetInstance()->LoadTexture("data/map/block.bmp");
}

float posX = 0;
float posY = 0;
float ax = 0;
float ay = 0;

void Stage::Move()
{
	float speed = 80.0f;

	// 操作
	if (DirectXLib::GetInstance()->IsKeyDown(DIK_LEFT))
	{
		posX -= speed * DirectXLib::GetInstance()->GetLoopTime();
	}
	
	if (DirectXLib::GetInstance()->IsKeyDown(DIK_RIGHT))
	{
		posX += speed * DirectXLib::GetInstance()->GetLoopTime();
	}
	
	if (DirectXLib::GetInstance()->IsKeyDown(DIK_UP))
	{
		posY -= speed * DirectXLib::GetInstance()->GetLoopTime();
	}
	
	if (DirectXLib::GetInstance()->IsKeyDown(DIK_DOWN))
	{
		posY += speed * DirectXLib::GetInstance()->GetLoopTime();
	}
}

void Stage::Draw()
{
	/*
	// マップデータ
	int mapdata[15][39] =
	{
		{210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210},
		{210, 210,  50,  51, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210,  50,  51, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210},
		{210, 210,  66,  67, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210,  66,  67, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210},
		{210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210},
		{210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210},
		{210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210},
		{210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210},
		{210, 129, 210, 210, 210, 129, 210, 210, 210, 210, 210, 210, 129, 210, 210, 210, 210, 129, 210, 210, 129, 210, 210, 210, 129, 210, 210, 210, 210, 210, 210, 129, 210, 210, 210, 210, 129, 210, 210},
		{210, 145, 210, 210, 210, 145, 210, 210, 210, 210, 210, 210, 145, 210, 210, 210, 210, 145, 210, 210, 145, 210, 210, 210, 145, 210, 210, 210, 210, 210, 210, 145, 210, 210, 210, 210, 145, 210, 210},
		{160, 161, 162, 210, 160, 161, 162, 210, 129, 210, 210, 160, 161, 162, 210, 210, 160, 161, 162, 210, 161, 162, 210, 160, 161, 162, 210, 129, 210, 210, 160, 161, 162, 210, 210, 160, 161, 162, 210},
		{176, 177, 178, 210, 176, 177, 178, 210, 145, 210, 210, 176, 177, 178, 210, 210, 176, 177, 178, 210, 177, 178, 210, 176, 177, 178, 210, 145, 210, 210, 176, 177, 178, 210, 210, 176, 177, 178, 210},
		{192, 193, 194, 210, 192, 193, 194, 160, 161, 162, 210, 192, 193, 194, 210, 210, 192, 193, 194, 210, 193, 194, 210, 192, 193, 194, 160, 161, 162, 210, 192, 193, 194, 210, 210, 192, 193, 194, 210},
		{245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246, 245, 246},
		{  0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1},
		{ 16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17,  16,  17},
	};

	int xx = (int)posX;
	int yy = (int)posY;

	// マップ描画
	for (int y = 0; y < 15; y++)
	{
		for (int x = 0; x < 39; x++)
		{
			DrawTexture(texture, (x*16 - (xx)), ((y-1)*16 - (yy)), mapdata[y][x]);
		}
	}
	*/
}
