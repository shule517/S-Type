#pragma once
#include <DirectXLib.h>
#include <vector>
#import <msxml6.dll>

class Frame
{
public:
	string imagePath;
	string soundPath;
	int x, y, w, h, gap;
};

typedef vector<Frame> FrameList;
typedef vector<FrameList> Animation;


class Anime : public DirectXLib
{
public:
	Anime(char* file_name);
	~Anime(void);

public:
	void Draw(int x, int y);
	
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
	char texturePath[64];
	Animation animation;
	float count;
};
