#include "StdAfx.h"
#include "Anime.h"

/*-------------------------------------------
	コンストラクタ
	引数：読む込むAnime(XML)ファイルパス
--------------------------------------------*/
Anime::Anime(char* file_name)
:isMirror(false), animeNo(0), count(0)
{
	// XML読み込み
	ReadXML(file_name);
}

/*-------------------------------------------
	デストラクタ
--------------------------------------------*/
Anime::~Anime()
{
}

bool Anime::ReadXML(char* file_name)
{
	// COMの初期化
	CoInitialize(NULL);

	// Documentの作成
	MSXML2::IXMLDOMDocument2Ptr pDocument;
	HRESULT hr = pDocument.CreateInstance(__uuidof(MSXML2::DOMDocument60), NULL, CLSCTX_INPROC_SERVER);

	if (FAILED(hr))
		return false;

	try
	{
		// パーサの設定
		pDocument->async = VARIANT_FALSE;
		pDocument->validateOnParse = VARIANT_FALSE;
		pDocument->resolveExternals = VARIANT_FALSE;
		pDocument->preserveWhiteSpace = VARIANT_FALSE;

		// xmlファイルを読み込む
		if (pDocument->load(file_name) == VARIANT_TRUE)
		{
			// 読みだし
			MSXML2::IXMLDOMNodeListPtr pList;
			MSXML2::IXMLDOMElementPtr pRoot;
			
			// pList = objectリスト
			pList = pDocument->selectNodes("object");

			// pRoot = object[0]
			if (pList->length > 0)
				pRoot = pList->item[0];
			else
				return false;

			// pList = animationリスト
			pList = pRoot->selectNodes("//animation");

			for (int i = 0; i < pList->length; i++)
			{
				pRoot = pList->item[i];
				FrameList frameList = GetAnimation(pRoot);
				animation.push_back(frameList);
			}

			/*
			// pList = animationリスト
			pList = pRoot->selectNodes("//animation");

			for (int i = 0; i < pList->length; i++)
			{
				// animation
				MSXML2::IXMLDOMElementPtr pRoot = pList->item[i];
				MSXML2::IXMLDOMNodeListPtr pList = pRoot->selectNodes("frame");

				for (int j = 0; j < pList->length; j++)
				{
					MSXML2::IXMLDOMElementPtr pRoot = pList->item[j];

					// メッセージボックス表示
					char data[256];
					sprintf(data, "animationNum = %s", pRoot->getAttribute("x"));
					MessageBox(0, data, 0, 0);
				}
			}

			/*
			// BSTR → char 変換
			WideCharToMultiByte(
				CP_ACP,			// コードページ ANSI コードページ
				0,			// 処理速度とマッピング方法を決定するフラグ
				(OLECHAR*)pRoot->getAttribute("image").bstrVal,		// ワイド文字列のアドレス
				-1,			// ワイド文字列の文字数
				texturePath,			// 新しい文字列を受け取るバッファのアドレス
				sizeof(texturePath) - 1,		// 新しい文字列を受け取るバッファのサイズ
				NULL,			// マップできない文字の既定値のアドレス
				NULL			// 既定の文字を使ったときにセットするフラグのアドレス
			);

			// テクスチャの初期化
			LoadTexture(texturePath);

			/*
			// メッセージボックス表示
			char data[256];
			sprintf(data, "image=%s x=%d w=%d", texturePath, _wtoi(pRoot->getAttribute("x").bstrVal), _wtoi(pRoot->getAttribute("w").bstrVal));
			MessageBox(0, data, 0, 0);
			*/
		}
		else
		{
			char data[256];
			sprintf_s(data, "%d行\n%s", pDocument->parseError->line, pDocument->parseError->srcText);
			MessageBox(NULL, data, "XMLパース Error!!", MB_OK);
			return false;
		}
	}
	// Error
	catch (_com_error error)
	{
		MessageBox(NULL, error.ErrorMessage(), "COM Error!!", MB_OK);
		return false;
	}

	return true;
}
/*-------------------------------------------
	
--------------------------------------------*/
Frame Anime::GetFrame(MSXML2::IXMLDOMElementPtr pRoot)
{
	Frame frame;
	frame.imagePath = toStr(pRoot->getAttribute("image").bstrVal);
	frame.x = toInt(pRoot->getAttribute("x").bstrVal);
	frame.y = toInt(pRoot->getAttribute("y").bstrVal);
	frame.w = toInt(pRoot->getAttribute("w").bstrVal);
	frame.h = toInt(pRoot->getAttribute("h").bstrVal);
	frame.gap = toInt(pRoot->getAttribute("gap").bstrVal);

	// TODO 音声の指定も行えるようにしたい
	//frame.soundPath = toStr(pRoot->getAttribute("image").bstrVal);

	return frame;
}

/*-------------------------------------------

--------------------------------------------*/
FrameList Anime::GetAnimation(MSXML2::IXMLDOMElementPtr pRoot)
{
	MSXML2::IXMLDOMNodeListPtr pList = pRoot->selectNodes("frame");

	FrameList frameList;

	for (int i = 0; i < pList->length; i++)
	{
		Frame frame = GetFrame(pList->item[i]);
		frameList.push_back(frame);
	}

	return frameList;
}

/*-------------------------------------------
	アニメーション描画
	引数：x:X座標, y:Y座標
--------------------------------------------*/
void Anime::Draw(long x, long y)
{
	FrameList frameList = animation[animeNo % animation.size()];

	if (frameList.size() > 0)
	{
		Frame frame = frameList.at((long)count % frameList.size());
		count += frame.gap / 60.0f;
	
		RECT rect = { frame.x, frame.y, frame.x + frame.w, frame.y + frame.h };
		DrawTexture(LoadTexture(frame.imagePath.c_str()), x, y, rect, isMirror);
	}
}
