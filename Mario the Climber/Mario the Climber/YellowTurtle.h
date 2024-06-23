#pragma once
#include "Turtle.h"

class YellowTurtle : public Turtle
{
public:

	YellowTurtle(const Vector2f& position)
	{
		_texture = new Texture;
		_texture->loadFromFile("Asset/Images/shell_amarillo.png");
		_sprite = new Sprite(*_texture);
		_sprite->setPosition(position);
		_sprite->setOrigin(_sprite->getOrigin().x / 2, _sprite->getOrigin().y - 15);
		_globalBounds = _sprite->getGlobalBounds();
		_speed = 50.f;
	}

	void SetPosition(const Vector2f& pos) override
	{
		_position = pos;
		_sprite->setPosition(_position);
	}

	void Move(float dx, float dy) override
	{
		_position.x += dx;
		_position.y += dy;
		_sprite->setPosition(_position);
	}

	Vector2f GetPosition() override
	{
		return _position;
	}

	FloatRect GetGlobalBounds() override
	{
		return _globalBounds;
		_position = _sprite->getPosition();
		_globalBounds = _sprite->getGlobalBounds();
	}

	void Update(float deltaTime) override
	{
		_sprite->move(_speed * deltaTime, 0.f);
	}

	void Draw(RenderWindow* window) override
	{
		window->draw(*_sprite);
	}
};