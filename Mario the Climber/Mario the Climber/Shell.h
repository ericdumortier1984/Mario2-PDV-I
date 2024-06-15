#pragma once
#include "Includes&usings.h"

class Shell
{
	friend class Game;
private:

	Texture* _shellTx;
	Sprite* _shellSp;

public:

	Shell(int _posX, int _posY);
	Shell* _nextShell;
};