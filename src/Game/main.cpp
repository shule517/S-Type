#include "StdAfx.h"
#include <GameLib.h>

// �G���g��
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	// �Q�[�������s
	GameLib *game = new GameLib();
	game->DoMainLoop();
	delete game;

	return 0;
}
