#include "Stack.h"

Stack::Stack(float h)
{
	_floor = h;

	_stackIsEmpty1 = true; 
	_stackIsEmpty2 = true; 

	LoadStack();
}

void Stack::Draw(RenderWindow& window)
{

	Node* _aux;

	if (_stack1)
	{
		_aux = _stack1;

		while (_aux)
		{
			_aux->Draw(window);
			_aux = _aux->_next;
		}

		_stack1->Draw(window);
	}

	Node* _aux2;

	if (_stack2)
	{
		_aux2 = _stack2;

		while (_aux2)
		{
			_aux2->Draw(window);
			_aux2 = _aux2->_next;
		}

		_stack2->Draw(window);
	}
}

void Stack::LoadStack()
{

	_posStack1 = 800; 
	_posStack2 = 0; 
	_indexColorStack1 = 0;
	_colorStack1 = "verde";

	for (int j = 0; j < 4; j++) 
	{
		PushStack1(_newNode);
	}
}


void Stack::PushStack1(Node* newNode)
{
	
	_posStack1 -= 30; 

	switch (_indexColorStack1)
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

	_newNode = new Node({ _posStack1, _floor }, _colorStack1);
	_newNode->_next = _stack1; 
	_stack1 = _newNode; 

	if (_indexColorStack1 < 3)
	{
		_indexColorStack1++;
	}

	else
	{
		_indexColorStack1 = 0;
	}
}

void Stack::PopStack1()
{

	if ((_stack1) && (_stack1->GetPosX() < _posStack2 + 31))
	{
		Node* _aux = _stack1; 
		_aux->GetSprite() = _stack1->GetSprite(); 
		_colorStack2 = _aux->GetColor(); 
		_stack1 = _aux->_next;
	
		PushStack2(_aux); 
	}

	if (_stack1 == NULL)
	{
		_posStack1 = 800;
		_stackIsEmpty1 = true;
		_stackIsEmpty2 = false;
	}
}


void Stack::PushStack2(Node* aux2)
{

	_posStack2 += 30; 

	aux2 = new Node({ _posStack2, _floor }, _colorStack2); 
	aux2->_next = _stack2; 
	_stack2 = aux2; 
}


void Stack::PopStack2()
{
	
	if ((_stack2) && (_stack2->GetPosX() > _posStack1 - 31))
	{
		Node* _aux2 = _stack2; 
		_aux2->GetSprite() = _stack2->GetSprite(); 
		_colorStack1 = _aux2->GetColor();
		_stack2 = _aux2->_next;
		
		PushStack2(_aux2); 
	}

	if (_stack2 == NULL)
	{
		_posStack2 = 0;
		_stackIsEmpty1 = false;
		_stackIsEmpty2 = true;
	}
}

void Stack::MoveStack()
{
	
	if ((_stackIsEmpty2) && (_stack1 != NULL))
	{
		_stack1->Move(-6); 
	}

	if ((_stackIsEmpty1) && (_stack2 != NULL))
	{
		_stack2->Move(6); 
	}
}

Sprite Stack::GetSpriteStack1()
{
	if (_stack1)
	{
		return _stack1->GetSprite();
	}
}

Sprite Stack::GetSpriteStack2()
{
	if (_stack2)
	{
		return _stack2->GetSprite();
	}
}