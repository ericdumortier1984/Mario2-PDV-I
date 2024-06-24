#pragma once //Evita definiciones duplicadas
#include "Includes&usings.h" //Contiene bibliotecas y definiciones utilizadas en el codigo

class Node 
{
private:

	friend class Stack; /*Clases amigas que pueden acceder */
	friend class Tail;  /* a los miembros privados de la clase Node */

	Vector2f _position; //Posicion del nodo en 2 coordenadas float
	Sprite* _sprite; //Puntero a objeto Sprite
	Texture* _texture; //Puntero a objeto Texture
	string _colorNode; //String para declarar el color del nodo
	Node* _next; //Puntero a otro objeto Node para formar la estuctura de datos

public:

	Node(Vector2f pos, string color); //Constuctor que toma la posicion y el color del nodo como parametros
	~Node(); //Deconstuctor

	//Funciones miembros publicas sin retorno
	void Draw(RenderWindow& window); //Permite dibujar el nodo pasando la ventana como referencia
	void InitNode(); //Permite inicializar el nodo
	void Move(int vel); //Permite mover el nodo tomando como parametro un entero para aplicarle la velocidad
	void SetTexture(string texture); //Permite establecer la textura del nodo para cambiar su color
	void SetPosition(Vector2f pos); //Permite establecer la posicion del nodo tomando las coordenadas en flotante como parametro

	//Funciones miembros publicas con retorno
	float GetPosX(); //Permite obtener la posicion en X del nodo
	Sprite GetSprite(); //Permite obtener su Sprite
	String GetColor(); //Permite obtener el color del nodo
};