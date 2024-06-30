#pragma once
#include "Includes&usings.h"

class Audio
{
private:

	// Punteros a los objetos Sound que representan los diferentes sonidos
	Sound* _jump;
	Sound* _clock;
	// Punteros a los objetos SoundBuffer que contienen los datos de los archivos de sonido
	SoundBuffer* _jumpBuffer;
	SoundBuffer* _clockBuffer;

public:

	// Constructor y destructor de la clase Audio
	Audio();
	~Audio();

	void PlayJump();// Reproduce el sonido de un salto
	void PlayClock();// Reproduce el sonido de un reloj
	void StopClock();// Detiene la reproducción del sonido del reloj
};