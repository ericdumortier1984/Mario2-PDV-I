#pragma once
#include "Includes&usings.h"
#include "Node.h"

class Stack
{
private:

	float _floor;

	int _indexColorStack1;
	int _indexColorStack2;
	string _colorStack1;
	string _colorStack2;

	Node* _stack1 = NULL; 
	Node* _stack2 = NULL; 
	Node* _newNode;

	float _posStack1; 
	float _posStack2; 

	bool _stackIsEmpty1;
	bool _stackIsEmpty2;

public:

	Stack(float h); 
	void Draw(RenderWindow& window); 

	void LoadStack();
	void PushStack1(Node* newNode);
	void PushStack2(Node* aux);
	void PopStack1(); 
	void PopStack2(); 
	void MoveStack(); 

	Sprite GetSpriteStack1();
	Sprite GetSpriteStack2();
};
