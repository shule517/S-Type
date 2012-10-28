#pragma once

class StageManager
{
public:
	static StageManager* GetInstance();
	void SetStagePos(const long x, const long y);
	D3DXVECTOR2 GetStagePos();
	void Move();

private:
	StageManager();
	virtual ~StageManager();

private:
	long stagePosX;
	long stagePosY;
};
