#pragma once //Directiva para evitar inclusiones múltiples del archivo
#include "Includes&usings.h" //Incluye archivos y definiciones de uso general
#include "Node.h"

class Tail
{
private:

	float _floor; //Altura del piso como número flotante
	int _indexColorTail; //Índice del color actual de la cola como número entero
	string _colorTail; //Color actual de la cola como cadena de texto

	Node* _firstTail = NULL; //Puntero al primer nodo de la cola
	Node* _lastTail = NULL; //Puntero al último nodo de la cola
	float _posTail; //Posición inicial de la cola como flotante

public:

	Tail(float h); //Constuctor que toma la posicion del piso como parámetro
	~Tail(); // Deconstructor
	
	//Funciones miembros publicas sin retorno
	void Draw(RenderWindow& window); //Permite dibujar la cola pasando la ventana como referencia
	void LoadTail(); //Permite inicializar la cola
	void PushTail(); //Permite agregar nodos en la cola
	void PopTail(); //Permite eliminar nodos de la cola
	void UpdateTail(); //permite actualizar la cola
	void MoveTail(); //Permite mover la cola

	//Función miembro publica con retorno
	Sprite GetSprite(); //Permite obtener el sprite del primer nodo de la cola
};