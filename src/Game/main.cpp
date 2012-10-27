#include "StdAfx.h"
#include <GameLib.h>

// エントリ
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	// ゲームを実行
	GameLib *game = new GameLib();
	game->DoMainLoop();
	delete game;

	return 0;
}
