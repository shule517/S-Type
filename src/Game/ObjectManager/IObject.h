#pragma once

class IObject
{
public:
	IObject()
	:posX(0),
	posY(0),
	imageWidth(0),
	imageHeight(0),
	boundsWidth(0),
	boundsHeight(0)
	{};
	virtual ~IObject(){};

	virtual void Init()= 0;	// ‰Šú‰»
	virtual void Move()= 0;	// ˆÚ“®
	virtual void Draw()= 0;	// •`‰æ

protected:
	long posX;				// XÀ•W
	long posY;				// YÀ•W
	long imageWidth;		// ‰æ‘œ•
	long imageHeight;		// ‰æ‘œ‚‚³
	long boundsWidth;		// “–‚½‚è”»’è(•)
	long boundsHeight;		// “–‚½‚è”»’è(‚‚³)
};
