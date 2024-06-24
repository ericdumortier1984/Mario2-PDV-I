#include "Node.h"

Node::Node(Vector2f pos, string color)
{
	_position = pos;
	_colorNode = color;

	InitNode();
}


void Node::Draw(RenderWindow& window)
{
	window.draw(*_sprite);
}

void Node::InitNode()
{
	_texture = new Texture;
	_texture->loadFromFile("Asset/Images/shell_" + _colorNode + ".png");
	_sprite = new Sprite(*_texture);
	_sprite->setTexture(*_texture);
	_sprite->setOrigin(15, 24); 
	_sprite->setPosition(_position);
}


void Node::SetTexture(string texture)
{
	_texture->loadFromFile(texture);
}


Sprite Node::GetSprite()
{
	return *_sprite;
}


void Node::Move(int vel) 
{
	float _x, _y;
	_x = _sprite->getPosition().x;
	_y = _sprite->getPosition().y;

	_sprite->setPosition(_x + vel, _y);
}

float Node::GetPosX()
{
	return _sprite->getPosition().x;
}


void Node::SetPosition(Vector2f pos)
{
	_sprite->setPosition(pos);
}


String Node::GetColor()
{
	return _colorNode;
}