#include "Audio.h"

Audio::Audio()
{
	// En el constructor, se asigna un objeto Sound y un objeto SoundBuffer a cada uno de los sonidos
	_jump = new Sound;
	_jumpBuffer = new SoundBuffer();
	_jumpBuffer->loadFromFile("Asset/Sound/jump!.ogg");// Carga el archivo de sonido en el SoundBuffer
	_jump->setBuffer(*_jumpBuffer);// Asigna el SoundBuffer al objeto Sound

	_clock = new Sound;
	_clockBuffer = new SoundBuffer();
	_clockBuffer->loadFromFile("Asset/Sound/tic-tac.ogg");// Carga el archivo de sonido en el SoundBuffer
	_clock->setBuffer(*_clockBuffer);// Asigna el SoundBuffer al objeto Sound
}

Audio::~Audio()
{
	// En el destructor, se eliminan los objetos Sound y SoundBuffer
	delete _fall;
	delete _clock;
	delete _jump;
}

void Audio::PlayJump()
{
	// Reproduce el sonido de un salto
	_jump->play();
}

void Audio::PlayClock()
{
	// Reproduce el sonido del reloj y lo configura para que se reproduzca en bucle
	_clock->play();
	_clock->setLoop(true);
}

void Audio::StopClock()
{
	// Detiene la reproducción del sonido del reloj
	_clock->stop();
}