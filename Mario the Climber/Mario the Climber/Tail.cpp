#include "Tail.h"

//Constructor de la clase "Tail", que toma la altura del piso como par�metro y llama a la funci�n "LoadTail()"
Tail::Tail(float h) 
{
	_floor = h;
	LoadTail(); 
}

/* Esta funci�n inicializa la cola, estableciendo la posici�n inicial, */
/* el �ndice y el color del primer nodo, */
/* y luego agrega 4 nodos a la cola utilizando la funci�n "PushTail()" */
void Tail::LoadTail()
{
	_posTail = 30; 
	_indexColorTail = 0;
	_colorTail = "verde";

	for (int i = 0; i < 4; i++)
	{
		_posTail = 30 - i * 30;
		PushTail();
	}
}

/* Esta funci�n agrega un nuevo nodo a la cola, estableciendo su color y posici�n, */
/* y actualizando los punteros al primer y �ltimo nodo de la cola */
void Tail::PushTail()
{
	
	switch (_indexColorTail)
	{
	case 0:
		_colorTail = "verde";
		break;

	case 1:
		_colorTail = "azul";
		break;

	case 2:
		_colorTail = "rojo";
		break;

	case 3:
		_colorTail = "amarillo";
		break;
	}

	Node* _newNode = new Node({ _posTail, _floor }, _colorTail); 
	_newNode->_next = NULL; 

	
	if (!_firstTail)
	{
		_firstTail = _newNode; 
	}

	else
	{
		
		_lastTail->_next = _newNode;
	}

	_lastTail = _newNode;

	if (_indexColorTail < 3)
	{
		_indexColorTail++;
	}

	else
	{
		_indexColorTail = 0;
	}
}

/* Esta funci�n elimina el primer nodo de la cola, */
/* actualizando los punteros y llamando a la funci�n "UpdateTail()" */
/* para ajustar la posici�n de los nodos restantes */
void Tail::PopTail()
{

	if (_firstTail->GetPosX() > 800) 
	{
		Node* _aux = _firstTail; 
		_aux->GetSprite() = _firstTail->GetSprite(); 
		_firstTail = _aux->_next; 
		delete _aux; 
		UpdateTail(); 
		PushTail(); 
	}
}

//Esta funci�n dibuja todos los nodos de la cola en la ventana de renderizado proporcionada
void Tail::Draw(RenderWindow& window)
{

	Node* _auxTail;

	if (_firstTail)
	{
		_auxTail = _firstTail;

		while (_auxTail)
		{
			_auxTail->Draw(window);
			_auxTail = _auxTail->_next;
		}

		_firstTail->Draw(window);
	}
}

//Esta funci�n mueve la cola desplazando el primer nodo pasando un entero como par�metro para darle velocidad
void Tail::MoveTail()
{
	
	if (_firstTail)
	{
		_firstTail->Move(4);
	}
}

//Esta funci�n actualiza la posici�n de los nodos de la cola, estableciendo la posici�n correcta de cada nodo
void Tail::UpdateTail()
{

	Node* _aux3;

	if (_firstTail)
	{
		_firstTail->SetPosition({ 30, _floor });
		_aux3 = _firstTail;
		_aux3 = _aux3->_next;
		_aux3->SetPosition({ 60, _floor });
		_aux3 = _aux3->_next;
		_aux3->SetPosition({ 90, _floor });
	}
}

//Esta funci�n devuelve el sprite del primer nodo de la cola
Sprite Tail::GetSprite()
{
	
	return _firstTail->GetSprite();
}

//Este destructor recorre la lista de nodos de la cola y libera la memoria asignada a cada uno de ellos
Tail::~Tail()
{
	Node* current = _firstTail;
	while (current != nullptr)
	{
		Node* next = current->_next;
		delete current;
		current = next;
	}
}
