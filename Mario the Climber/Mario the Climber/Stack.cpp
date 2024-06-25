#include "Stack.h"

Stack::Stack(float h)
{
	_floor = h; //Inicializa la altura del piso

	_stackIsEmpty1 = true; //Marca la primera pila como vacía
	_stackIsEmpty2 = true; //Marca la segunda pila como vacía

	LoadStack(); //Carga la primera pila
}

void Stack::Draw(RenderWindow& window)
{

	Node* _aux; //Puntero auxiliar para recorrer la primera pila

	if (_stack1) //Si la primera pila no está vacía
	{
		_aux = _stack1; //Asigna el primer nodo de la primera pila a _aux

		while (_aux) //Mientras haya nodos en la primera pila
		{
			_aux->Draw(window); //Dibuja cada nodo en la ventana de renderizado
			_aux = _aux->_next; //Avanza al siguiente nodo
		}

		_stack1->Draw(window); //Dibuja la primera pila
	}

	Node* _aux2; //Puntero auxiliar para recorrer la segunda pila

	if (_stack2) //Si la segunda pila no está vacía
	{
		_aux2 = _stack2; //Asigna el primer nodo de la segunda pila a _aux2

		while (_aux2) //Mientras haya nodos en la segunda pila
		{
			_aux2->Draw(window); //Dibuja cada nodo en la ventana de renderizado
			_aux2 = _aux2->_next; //Avanza al siguiente nodo
		}

		_stack2->Draw(window); //Dibuja la segunda pila
	}
}

void Stack::LoadStack()
{

	_posStack1 = 800; //Inicializa la posición horizontal de la primera pila
	_posStack2 = 0; //Inicializa la posición horizontal de la segunda pila
	_indexColorStack1 = 0; //Inicializa el índice de color de la primera pila
	_colorStack1 = "verde"; //Inicializa el color de la primera pila

	for (int j = 0; j < 4; j++) //Agrega 4 nodos a la primera pila
	{
		PushStack1(_newNode); //Llama a la función para agregar un nuevo nodo.
	}
}


void Stack::PushStack1(Node* newNode)
{
	
	_posStack1 -= 30; //Decrementa la posición horizontal de la primera pila en 30 unidades.

	switch (_indexColorStack1) //Establece el color de la nueva pieza en función del índice de color.
	{
	case 0:
		_colorStack1 = "verde";
		break;

	case 1:
		_colorStack1 = "azul";
		break;

	case 2:
		_colorStack1 = "rojo";
		break;

	case 3:
		_colorStack1 = "amarillo";
		break;
	}

	_newNode = new Node({ _posStack1, _floor }, _colorStack1); //Crea un nuevo nodo con la posición y el color correspondientes
	_newNode->_next = _stack1; //Enlaza el nuevo nodo al principio de la primera pila
	_stack1 = _newNode; //Actualiza el puntero al primer nodo de la primera pila

	if (_indexColorStack1 < 3) //Avanza el índice de color de la primera pila si no ha llegado al final.
	{
		_indexColorStack1++;
	}

	else //Reinicia el índice de color de la primera pila
	{
		_indexColorStack1 = 0;
	}
}

void Stack::PopStack1()
{

	if ((_stack1) && (_stack1->GetPosX() < _posStack2 + 31)) /* Si la primera pila no está vacía y */
		                                                     /* el último nodo está a menos de 31 unidades de la segunda pila */
	{
		Node* _aux = _stack1; //Guarda una referencia al último nodo de la primera pila
		_aux->GetSprite() = _stack1->GetSprite(); //Obtiene el sprite del último nodo
		_colorStack2 = _aux->GetColor(); //Obtiene el color del último nodo
		_stack1 = _aux->_next; //Actualiza el puntero al primer nodo de la primera pila
	
		PushStack2(_aux); //Agrega el nodo a la segunda pila
	}

	if (_stack1 == NULL) //Si la primera pila está vacía
	{
		_posStack1 = 800; //Reinicia la posición de la primera pila
		_stackIsEmpty1 = true; //Marca la primera pila como vacía
		_stackIsEmpty2 = false; //Marca la segunda pila como no vacía
	}
}


void Stack::PushStack2(Node* aux2)
{

	_posStack2 += 30; //Incrementa la posición horizontal de la segunda pila en 30 unidades

	aux2 = new Node({ _posStack2, _floor }, _colorStack2); //Crea un nuevo nodo con la posición y el color correspondientes
	aux2->_next = _stack2; //Enlaza el nuevo nodo al principio de la segunda pila
	_stack2 = aux2; //Actualiza el puntero al primer nodo de la segunda pila
}


void Stack::PopStack2()
{
	
	if ((_stack2) && (_stack2->GetPosX() > _posStack1 - 31)) /* Si la segunda pila no está vacía y */
		                                                     /* el último nodo está a más de 31 unidades de la primera pila */
	{
		Node* _aux2 = _stack2; //Guarda una referencia al último nodo de la segunda pila
		_aux2->GetSprite() = _stack2->GetSprite(); //Obtiene el sprite del último nodo
		_colorStack1 = _aux2->GetColor(); //Obtiene el color del último nodo
		_stack2 = _aux2->_next; //Actualiza el puntero al primer nodo de la segunda pila//Obtiene el color del último nodo
		
		PushStack2(_aux2); //Agrega el nodo a la primera pila
	}

	if (_stack2 == NULL) //Si la segunda pila está vacía
	{
		_posStack2 = 0; //Reinicia la posición de la segunda pila
		_stackIsEmpty1 = false; //Marca la primera pila como no vacía
		_stackIsEmpty2 = true; //Marca la segunda pila como vacía
	}
}

void Stack::MoveStack()
{
	
	if ((_stackIsEmpty2) && (_stack1 != NULL)) //Si la segunda pila está vacía y la primera pila no
	{
		_stack1->Move(-6); //Mueve la primera pila 6 unidades hacia la izquierda
	}

	if ((_stackIsEmpty1) && (_stack2 != NULL)) //Si la primera pila está vacía y la segunda pila no
	{
		_stack2->Move(6); //Mueve la segunda pila 6 unidades hacia la derecha
	}
}

Sprite Stack::GetSpriteStack1()
{
	if (_stack1) //Si la primera pila no está vacía
	{
		return _stack1->GetSprite(); //Devuelve el sprite del primer nodo de la primera pila
	}
}

Sprite Stack::GetSpriteStack2()
{
	if (_stack2) //Si la segunda pila no está vacía
	{
		return _stack2->GetSprite(); //Devuelve el sprite del primer nodo de la segunda pila
	}
}

Stack::~Stack()
{
	// Liberar memoria de la primera pila
	while (_stack1 != nullptr) //Mientras la primera pila no esté vacía
	{
		Node* temp = _stack1; //Guarda una referencia al primer nodo
		_stack1 = _stack1->_next; //Actualiza el puntero al primer nodo
		delete temp; //Libera la memoria del nodo
	}

	// Liberar memoria de la segunda pila
	while (_stack2 != nullptr) //Mientras la segunda pila no esté vacía
	{
		Node* temp = _stack2; //Guarda una referencia al primer nodo
		_stack2 = _stack2->_next; //Actualiza el puntero al primer nodo
		delete temp; //Libera la memoria del nodo
	}
}