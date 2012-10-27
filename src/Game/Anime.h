#pragma once
#include <DirectXLib.h>
#include <vector>
#import <msxml6.dll>

// アニメーションフレーム.
class Frame
{
public:
	string imagePath;	// 画像ファイルパス
	string soundPath;	// 音楽ファイルパス
	long x;				// 表示位置(X座標)
	long y;				// 表示位置(Y座標)
	long w;				// 画像幅
	long h;				// 画像高さ
	long gap;			// フレーム間待機時間
};

typedef vector<Frame> FrameList;
typedef vector<FrameList> Animation;

// アニメーションクラス
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
	char texturePath[MAX_PATH];	// 画像ファイルパス
	Animation animation;		// アニメーション
	float count;				// 
};
