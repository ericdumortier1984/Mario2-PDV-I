#pragma once
#include "Turtle.h"

class GreenTurtle : public Turtle
{
public:

	GreenTurtle(const Vector2f& position)
	{
		_texture = new Texture;
		_texture->loadFromFile("Asset/Images/shell_verde.png");
		_sprite = new Sprite(*_texture);
		_sprite->setPosition(position);
		_sprite->setOrigin(_sprite->getOrigin().x / 2, _sprite->getOrigin().y - 15);
		_speed = 50.f;
	}

	void Update(float deltaTime) override
	{
		_sprite->move(_speed * deltaTime, 0.f);
		// Agregar lógica de movimiento específica de la tortuga roja
	}

	void Draw(RenderWindow* window) override
	{
		window->draw(*_sprite);
	}


};