#include "Game.h"
// To fix: error de meoria al iniciar la pila 2
int main()
{

	Game* Go;// declara un puntero llamado Go que apunta a un objeto de la clase Game
	Go = new Game;// Crea una instancia de la clase Game y asigna su direcci�n de memoria al puntero Go
	Go->Loop();// LLamada al metodo Loop() del objeto Game al que apunta Go

	return EXIT_SUCCESS;// valor que indica al sistema operativo que el programa se cerr� exitosamente
}