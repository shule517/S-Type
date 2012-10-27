#include "StdAfx.h"
#include "Anime.h"

/*-------------------------------------------
	�R���X�g���N�^
	�����F�ǂލ���Anime(XML)�t�@�C���p�X
--------------------------------------------*/
Anime::Anime(char* file_name)
:isMirror(false), animeNo(0), count(0)
{
	// XML�ǂݍ���
	ReadXML(file_name);
}

/*-------------------------------------------
	�f�X�g���N�^
--------------------------------------------*/
Anime::~Anime()
{
}

bool Anime::ReadXML(char* file_name)
{
	// COM�̏�����
	CoInitialize(NULL);

	// Document�̍쐬
	MSXML2::IXMLDOMDocument2Ptr pDocument;
	HRESULT hr = pDocument.CreateInstance(__uuidof(MSXML2::DOMDocument60), NULL, CLSCTX_INPROC_SERVER);

	if (FAILED(hr))
		return false;

	try
	{
		// �p�[�T�̐ݒ�
		pDocument->async = VARIANT_FALSE;
		pDocument->validateOnParse = VARIANT_FALSE;
		pDocument->resolveExternals = VARIANT_FALSE;
		pDocument->preserveWhiteSpace = VARIANT_FALSE;

		// xml�t�@�C����ǂݍ���
		if (pDocument->load(file_name) == VARIANT_TRUE)
		{
			// �ǂ݂���
			MSXML2::IXMLDOMNodeListPtr pList;
			MSXML2::IXMLDOMElementPtr pRoot;
			
			// pList = object���X�g
			pList = pDocument->selectNodes("object");

			// pRoot = object[0]
			if (pList->length > 0)
				pRoot = pList->item[0];
			else
				return false;

			// pList = animation���X�g
			pList = pRoot->selectNodes("//animation");

			for (int i = 0; i < pList->length; i++)
			{
				pRoot = pList->item[i];
				FrameList frameList = GetAnimation(pRoot);
				animation.push_back(frameList);
			}

			/*
			// pList = animation���X�g
			pList = pRoot->selectNodes("//animation");

			for (int i = 0; i < pList->length; i++)
			{
				// animation
				MSXML2::IXMLDOMElementPtr pRoot = pList->item[i];
				MSXML2::IXMLDOMNodeListPtr pList = pRoot->selectNodes("frame");

				for (int j = 0; j < pList->length; j++)
				{
					MSXML2::IXMLDOMElementPtr pRoot = pList->item[j];

					// ���b�Z�[�W�{�b�N�X�\��
					char data[256];
					sprintf(data, "animationNum = %s", pRoot->getAttribute("x"));
					MessageBox(0, data, 0, 0);
				}
			}

			/*
			// BSTR �� char �ϊ�
			WideCharToMultiByte(
				CP_ACP,			// �R�[�h�y�[�W ANSI �R�[�h�y�[�W
				0,			// �������x�ƃ}�b�s���O���@�����肷��t���O
				(OLECHAR*)pRoot->getAttribute("image").bstrVal,		// ���C�h������̃A�h���X
				-1,			// ���C�h������̕�����
				texturePath,			// �V������������󂯎��o�b�t�@�̃A�h���X
				sizeof(texturePath) - 1,		// �V������������󂯎��o�b�t�@�̃T�C�Y
				NULL,			// �}�b�v�ł��Ȃ������̊���l�̃A�h���X
				NULL			// ����̕������g�����Ƃ��ɃZ�b�g����t���O�̃A�h���X
			);

			// �e�N�X�`���̏�����
			LoadTexture(texturePath);

			/*
			// ���b�Z�[�W�{�b�N�X�\��
			char data[256];
			sprintf(data, "image=%s x=%d w=%d", texturePath, _wtoi(pRoot->getAttribute("x").bstrVal), _wtoi(pRoot->getAttribute("w").bstrVal));
			MessageBox(0, data, 0, 0);
			*/
		}
		else
		{
			char data[256];
			sprintf_s(data, "%d�s\n%s", pDocument->parseError->line, pDocument->parseError->srcText);
			MessageBox(NULL, data, "XML�p�[�X Error!!", MB_OK);
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

	// TODO �����̎w����s����悤�ɂ�����
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
	�A�j���[�V�����`��
	�����Fx:X���W, y:Y���W
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
