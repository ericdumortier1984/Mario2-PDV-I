#pragma once //Directiva para evitar inclusiones m�ltiples del archivo
#include "Includes&usings.h" //Incluye archivos y definiciones de uso general
#include "Afichmation.h"
#include "Animation.h"
#include "Counter.h"
#include "Audio.h"
#include "Node.h"
#include "Stack.h"
#include "Tail.h"

class Game
{
private:
	// Propiedades relacionadas con el mundo del juego
	const int _w_x_min = 0;// L�mite izquierdo de la pantalla
	const int _w_x_max = 800;// L�mite derecho de la pantalla
	const float _floor[7] = { 30.f, 110.f, 180.f, 255.f, 335.f, 410.f, 480.f };// Posici�n de las plataformas
	const float _gravity = 0.5f;// Aceleraci�n de la gravedad

	//Creo las instancias del enemigo
	Stack* stack1 = NULL;
	Stack* stack2 = NULL;
	Stack* stack3 = NULL;
	Tail* tail1 = NULL;
	Tail* tail2 = NULL;
	Tail* tail3 = NULL;

	// Ventana del juego
	RenderWindow* _wnd;

	// Escenario de fondo
	Texture* _backTx;
	Sprite* _backSp;
	Texture* _doorTx;
	Sprite* _door;

	// Temporizador
	Counter* _timer;

	// Audio
	Audio* _audio;

	// Textos y fuente
	Font* _font;
	Text* _gameOverText;

	// Mario
	Texture* _marioTex;
	Afichmation* _mario;
	Vector2f _velocity;
	bool _isJumping;
	bool _runningLeft;
	bool _runningRight;

	// M�todos privados
	void DoEvents();// Maneja los eventos
	void InitMario();// Inicializa a Mario
	void ProcessCollision();// Procesa las colisiones entre Mario y las tortugas
	void DrawGame();
	void CheckGameConditions();// Verifica las condiciones de victoria o derrota
	void GameOver();// Muestra la pantalla de "Game Over"
	
	// Variables de estado del juego
	bool _gameOver;
	bool _youWin;

public:
	// Constructor y destructor
	Game();
	~Game();

	// M�todo p�blico
	void Loop();// Bucle principal del juego
};