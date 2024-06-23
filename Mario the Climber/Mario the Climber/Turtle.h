#pragma once
#include "Includes&usings.h"

class Turtle
{
protected:

	Texture* _texture;
	Sprite* _sprite;
	Vector2f _position;
	FloatRect _globalBounds;
	float _speed;

public:

	virtual void SetPosition(const Vector2f& pos) = 0;
	virtual void Move(float dx, float dy) = 0;
	virtual FloatRect GetGlobalBounds() = 0;
	virtual Vector2f GetPosition() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw(RenderWindow* window) = 0;
};