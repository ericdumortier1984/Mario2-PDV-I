#include "Tail.h"

//Constructor de la clase "Tail", que toma la altura del piso como parámetro y llama a la función "LoadTail()"
Tail::Tail(float h) 
{
	_floor = h; //Establece la altura del piso
	LoadTail(); //Llama a la función LoadTail() para inicializar la cola
}

/* Esta función inicializa la cola, estableciendo la posición inicial, */
/* el índice y el color del primer nodo, */
/* y luego agrega 4 nodos a la cola utilizando la función "PushTail()" */
void Tail::LoadTail()
{
	_posTail = 30; //Establece la posición inicial del primer nodo
	_indexColorTail = 0; //Inicializa el índice de color del primer nodo
	_colorTail = "verde"; //Establece el color inicial del primer nodo

	for (int i = 0; i < 4; i++) //Agrega 4 nodos a la cola
	{
		_posTail = 30 - i * 30; //Calcula la posición del nuevo nodo
		PushTail(); //Llama a la función PushTail() para agregar un nuevo nodo
	}
}

/* Esta función agrega un nuevo nodo a la cola, estableciendo su color y posición, */
/* y actualizando los punteros al primer y último nodo de la cola */
void Tail::PushTail()
{
	//Establece el color del nuevo nodo en función del índice de color
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

	//Crea un nuevo nodo con la posición y el color establecidos
	Node* _newNode = new Node({ _posTail, _floor }, _colorTail); 
	_newNode->_next = NULL; //Establece el siguiente nodo como NULL

	//Actualiza los punteros al primer y último nodo de la cola
	if (!_firstTail)
	{
		_firstTail = _newNode; //Si la cola está vacía, el nuevo nodo es el primero
	}

	else
	{
		
		_lastTail->_next = _newNode; //Si la cola no está vacía, el nuevo nodo se agrega al final
	}

	_lastTail = _newNode; //Actualiza el puntero al último nodo de la cola

	//Actualiza el índice de color para el siguiente nodo
	if (_indexColorTail < 3)
	{
		_indexColorTail++;
	}

	else
	{
		_indexColorTail = 0;
	}
}

/* Esta función elimina el primer nodo de la cola, */
/* actualizando los punteros y llamando a la función "UpdateTail()" */
/* para ajustar la posición de los nodos restantes */
void Tail::PopTail()
{

	if (_firstTail->GetPosX() > 800) //Si el primer nodo ha salido de la pantalla
	{
		Node* _aux = _firstTail; //Guarda una referencia al primer nodo
		_aux->GetSprite() = _firstTail->GetSprite(); //Copia el sprite del primer nodo
		_firstTail = _aux->_next; //Actualiza el puntero al primer nodo
		delete _aux;  //Elimina el primer nodo
		UpdateTail(); //Actualiza la posición de los nodos restantes
		PushTail(); //Agrega un nuevo nodo al final de la cola
	}
}

//Esta función dibuja todos los nodos de la cola en la ventana de renderizado proporcionada
void Tail::Draw(RenderWindow& window)
{

	Node* _auxTail;

	if (_firstTail) //Si la cola no está vacía
	{
		_auxTail = _firstTail; //Obtiene una referencia al primer nodo

		while (_auxTail) //Recorre la cola y dibuja cada nodo
		{
			_auxTail->Draw(window);
			_auxTail = _auxTail->_next;
		}

		_firstTail->Draw(window); //Dibuja el primer nodo de la cola
	}
}

//Esta función mueve la cola desplazando el primer nodo pasando un entero como parámetro para darle velocidad
void Tail::MoveTail()
{
	
	if (_firstTail) //Si la cola no está vacía
	{
		_firstTail->Move(4); //Mueve el primer nodo 4 unidades hacia la derecha
	}
}

//Esta función actualiza la posición de los nodos de la cola, estableciendo la posición correcta de cada nodo
void Tail::UpdateTail()
{

	Node* _aux3;

	if (_firstTail) //Si la cola no está vacía
	{
		_firstTail->SetPosition({ 30, _floor }); //Establece la posición del primer nodo
		_aux3 = _firstTail;
		_aux3 = _aux3->_next;
		_aux3->SetPosition({ 60, _floor }); //Establece la posición del segundo nodo
		_aux3 = _aux3->_next;
		_aux3->SetPosition({ 90, _floor }); //Establece la posición del tercer nodo
	}
}

//Esta función devuelve el sprite del primer nodo de la cola
Sprite Tail::GetSprite()
{
	
	return _firstTail->GetSprite(); //Devuelve el sprite del primer nodo de la cola
}

//Este destructor recorre la lista de nodos de la cola y libera la memoria asignada a cada uno de ellos
Tail::~Tail()
{
	Node* current = _firstTail;
	while (current != nullptr) //Mientras haya nodos en la cola
	{
		Node* next = current->_next; //Guarda una referencia al siguiente nodo
		delete current; //Elimina el nodo actual
		current = next; //Avanza al siguiente nodo
	}
}
