#include "Node.h"

//Cuerpo del constructor de la clase "Node".Aquí se inicializan los miembros de datos y se llama a la función "InitNode()"
Node::Node(Vector2f pos, string color)
{
	_position = pos;
	_colorNode = color;

	InitNode();
}

//Esta función dibuja el sprite del nodo en la ventana de renderizado proporcionada
void Node::Draw(RenderWindow& window)
{
	window.draw(*_sprite);
}

/* Esta función inicializa el nodo cargando la textura correspondiente al color del nodo, */
/* creando un objeto "Sprite" y estableciendo su posición */
void Node::InitNode()
{
	_texture = new Texture;
	_texture->loadFromFile("Asset/Images/shell_" + _colorNode + ".png");
	_sprite = new Sprite(*_texture);
	_sprite->setTexture(*_texture);
	_sprite->setOrigin(_sprite->getOrigin().x / 2, _sprite->getOrigin().y - 15);
	_sprite->setPosition(_position);
}

//Esta función establece una nueva textura para el sprite del nodo
void Node::SetTexture(string texture)
{
	_texture->loadFromFile(texture);
}

//Esta función devuelve una copia del sprite del nodo
Sprite Node::GetSprite()
{
	return *_sprite;
}

//Esta función mueve el nodo horizontalmente a una velocidad determinada.
void Node::Move(int vel) 
{
	float _x, _y;
	_x = _sprite->getPosition().x;
	_y = _sprite->getPosition().y;

	_sprite->setPosition(_x + vel, _y);
}

//Esta función devuelve la coordenada x de la posición del nodo.
float Node::GetPosX()
{
	return _sprite->getPosition().x;
}

//Esta función establece la posición del nodo.
void Node::SetPosition(Vector2f pos)
{
	_sprite->setPosition(pos);
}

//Esta función devuelve el color del nodo.
String Node::GetColor()
{
	return _colorNode;
}

//En el deconstructor eliminamos objetos para evitar fugas de memoria
Node::~Node()
{
	
	delete _sprite;
	delete _texture;
}
