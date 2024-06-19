#pragma once
#include "Includes&usings.h"

class Turtle
{
protected:

	Texture* _texture;
	Sprite* _sprite;
	Vector2f _position;
	float _speed;

public:

	virtual void Update(float deltaTime) = 0;
	virtual void Draw(RenderWindow* window) = 0;
};