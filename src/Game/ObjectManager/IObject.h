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
	boundsHeight(0),
	startAnimeNo(0)
	{};
	virtual ~IObject(){};

	virtual void Init()= 0;	// ������
	virtual void Move()= 0;	// �ړ�
	virtual void Draw()= 0;	// �`��
// TODO	virtual void Hit()=0;	// �Ԃ�����


	/*-------------------------------------------
	�I�u�W�F�N�g���m�̓����蔻��
	objectA / objectB�̓����蔻��`�F�b�N
	--------------------------------------------*/
// TODO bool IsHit(const IObject& a, const IObject& b)
	bool IsHit(const IObject& a, const IObject& b)
	{
		long ax1 = a.posX + (a.imageWidth  - a.boundsWidth) / 2;
		long ay1 = a.posY + (a.imageHeight - a.imageHeight) / 2;
		long ax2 = a.posX + (a.imageWidth  - a.boundsWidth) / 2;
		long ay2 = a.posY + (a.imageHeight - a.imageHeight) / 2;
		long bx1 = b.posX + (b.imageWidth  - a.boundsWidth) / 2;
		long by1 = b.posY + (b.imageHeight - a.imageHeight) / 2;
		long bx2 = b.posX + (b.imageWidth  - a.boundsWidth) / 2;
		long by2 = b.posY + (b.imageHeight - a.imageHeight) / 2;
		
		if ((ax1 < bx2) &&
			(bx1 < ax2) &&
			(ay1 < by2) &&
			(by1 < ay2))
		{
			return true;
		}
		
		return false;
	}

protected:
	long posX;				// X���W
	long posY;				// Y���W
	long imageWidth;		// �摜��
	long imageHeight;		// �摜����
	long boundsWidth;		// �����蔻��(��)
	long boundsHeight;		// �����蔻��(����)
	long startAnimeNo;		// �J�n�A�j��No
};
