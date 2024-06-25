#pragma once //Directiva para evitar inclusiones múltiples del archivo
#include "Includes&usings.h" //Incluye archivos y definiciones de uso general
#include "Node.h"

class Stack
{
private:

	float _floor; //Altura del piso como número flotante
	
	int _indexColorStack1; //Índice del color actual de la primera pila como número entero
	int _indexColorStack2; //Índice del color actual de segunda pila como número entero
	string _colorStack1; //Almacena el color actual de la primera pila
	string _colorStack2; //Almacena el color actual de la segunda pila

	Node* _stack1 = NULL; //Puntero al primer nodo de la primera pila
	Node* _stack2 = NULL; //Puntero al primer nodo de la segunda pila
	Node* _newNode; //Puntero a un nuevo nodo

	float _posStack1; //Almacena la posición horizontal de la primera pila
	float _posStack2; //Almacena la posición horizontal de la segunda pila

	bool _stackIsEmpty1; //Indica si la primera pila está vacía
	bool _stackIsEmpty2; //Indica si la segunda pila está vacía

public:

	Stack(float h); //Constructor de la clase Stack que recibe la altura del piso como parámetro
	~Stack(); //Destructor de la clase Stack

	//Funciones miembros publicas sin retorno
	void Draw(RenderWindow& window); //Permite dibujar las pilas pasando la ventana como referencia
	void LoadStack(); //Carga la primera pila con 4 nodos
	void PushStack1(Node* newNode); //Agrega un nuevo nodo a la primera pila
	void PushStack2(Node* aux); //Agrega un nodo a la segunda pila
	void PopStack1(); //Elimina un nodo de la primera pila
	void PopStack2(); //Elimina un nodo de la segunda pila
	void MoveStack(); //Mueve las pilas hacia la izquierda o derecha

	//Funciónes miembros publicas con retorno
	Sprite GetSpriteStack1(); //Devuelve el sprite de la primera pila
	Sprite GetSpriteStack2(); //Devuelve el sprite de la segunda pila
};
