#pragma once

class StageManager
{
public:
	StageManager();
	virtual ~StageManager();

	static StageManager* GetInstance();
	void SetStagePos(const long x, const long y);
	D3DXVECTOR2 GetStagePos();
	void Move();

private:
	long stagePosX;
	long stagePosY;
};
