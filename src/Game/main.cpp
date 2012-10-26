#include "StdAfx.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	Game *game = new Game();
	game->DoMainLoop();

	delete game;

	return 0;
}
