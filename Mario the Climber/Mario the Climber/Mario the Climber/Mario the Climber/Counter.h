#pragma once
#include "Includes&usings.h"

class Counter
{
private:

	// Punteros a los objetos que se utilizan para el contador de tiempo
	Clock* _clock;// Objeto Clock para medir el tiempo
	Time* _time;// Objeto Time para almacenar el tiempo transcurrido
	Font* _font; // Objeto Font para la fuente del texto del contador
	Text* _textCounter;// Objeto Text para mostrar el contador de tiempo
	// Variables de estado del contador
	int _counterTime;// Tiempo total del contador en segundos
	int _initTime;// Tiempo inicial del contador en segundos
	bool _timeUp;// Indica si el tiempo se ha agotado

public:

	// Constructor y destructor de la clase Counter
	Counter();
	~Counter();

	// M�todos de la clase Counter
	bool TimeUp();// Devuelve true si el tiempo se ha agotado
	void InitCounter();// Inicializa el contador de tiempo
	void UpdateCounter();// Actualiza el tiempo restante del contador
	void StopCounter();// Detiene el contador de tiempo
	void UpdateTextCounter();// Actualiza el texto que muestra el contador de tiempo
	void Draw(RenderWindow& _wnd);// Dibuja el contador de tiempo en la ventana
};