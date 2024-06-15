#include "Shell.h"

Shell::Shell(int _posX, int _posY)
{

	_shellTx = new Texture;
	_shellTx->loadFromFile("Asset/Images/shell_amarillo.png");
	_shellSp = new Sprite;
	_shellSp->setTexture(*_shellTx);
	_shellSp->setPosition(_posX, _posY);
}