#pragma once //Evita definiciones duplicadas
#include "Includes&usings.h" //Contiene bibliotecas y definiciones utilizadas en el codigo
#include "Node.h"

class Stack
{
private:

	float _floor; //Altura del piso como n�mero flotante
	
	int _indexColorStack1; //�ndice del color actual de la primera pila como n�mero entero
	int _indexColorStack2; //�ndice del color actual de segunda pila como n�mero entero
	string _colorStack1; //
	string _colorStack2; //

	Node* _stack1 = NULL; 
	Node* _stack2 = NULL; 
	Node* _newNode;

	float _posStack1; 
	float _posStack2; 

	bool _stackIsEmpty1;
	bool _stackIsEmpty2;

public:

	Stack(float h); 
	~Stack();

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
