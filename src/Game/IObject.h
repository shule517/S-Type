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

	virtual void Init()= 0;	// ������
	virtual void Move()= 0;	// �ړ�
	virtual void Draw()= 0;	// �`��

protected:
	long posX;				// X���W
	long posY;				// Y���W
	long imageWidth;		// �摜��
	long imageHeight;		// �摜����
	long boundsWidth;		// �����蔻��(��)
	long boundsHeight;		// �����蔻��(����)
};
