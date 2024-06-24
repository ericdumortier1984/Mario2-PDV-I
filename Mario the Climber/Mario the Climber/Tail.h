#pragma once
#include "Includes&usings.h"
#include "Node.h"

class Tail
{
private:

	float _floor;
	int _indexColorTail;
	string _colorTail;

	Node* _firstTail = NULL;
	Node* _lastTail = NULL;
	float _posTail; 

public:

	Tail(float h);
	void Draw(RenderWindow& window); 

	void LoadTail();
	void PushTail(); 
	void PopTail(); 
	void UpdateTail();
	void MoveTail(); 
	Sprite GetSprite(); 
};