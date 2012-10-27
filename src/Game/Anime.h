#pragma once
#include <DirectXLib.h>
#include <vector>
#import <msxml6.dll>

// �A�j���[�V�����t���[��.
class Frame
{
public:
	string imagePath;	// �摜�t�@�C���p�X
	string soundPath;	// ���y�t�@�C���p�X
	long x;				// �\���ʒu(X���W)
	long y;				// �\���ʒu(Y���W)
	long w;				// �摜��
	long h;				// �摜����
	long gap;			// �t���[���ԑҋ@����
};

typedef vector<Frame> FrameList;
typedef vector<FrameList> Animation;

// �A�j���[�V�����N���X
class Anime
{
public:
	Anime(char* file_name);
	~Anime();

public:
	void Draw(long x, long y);
	
	void setMirror(bool mirror)
	{
		isMirror= mirror;
	}

	bool getMirror()
	{
		return isMirror;
	}

	void setAnime(int anime_no)
	{
		animeNo = anime_no;
	}
		
	int toInt(BSTR str)
	{
		return _wtoi(str);
	}

	char* toStr(BSTR str)
	{
		return _com_util::ConvertBSTRToString(str);
	}

private:
	Frame GetFrame(MSXML2::IXMLDOMElementPtr pRoot);
	FrameList GetAnimation(MSXML2::IXMLDOMElementPtr pRoot);
	bool ReadXML(char* file_name);

private:
	bool isMirror;
	int animeNo;
	char texturePath[MAX_PATH];	// �摜�t�@�C���p�X
	Animation animation;		// �A�j���[�V����
	float count;				// 
};
