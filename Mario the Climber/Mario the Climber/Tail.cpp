#include "Tail.h"

Tail::Tail(float h) 
{
	_floor = h;
	LoadTail(); 
}


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


void Tail::MoveTail()
{
	
	if (_firstTail)
	{
		_firstTail->Move(4);
	}
}


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


Sprite Tail::GetSprite()
{
	return _firstTail->GetSprite();
}