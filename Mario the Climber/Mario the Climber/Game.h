#pragma once
#include "Includes&usings.h"
#include "Afichmation.h"
#include "Animation.h"
#include "Counter.h"
#include "Audio.h"
#include "Turtle.h"
#include "RedTurtle.h"
#include "GreenTurtle.h"
#include "BlueTurtle.h"
#include "YellowTurtle.h"

class Game
{
private:
	// Propiedades relacionadas con el mundo del juego
	const int _w_x_min = 0;// Límite izquierdo de la pantalla
	const int _w_x_max = 800;// Límite derecho de la pantalla
	const int _floor[7] = { 30, 110, 180, 255, 335, 410, 480 };// Posicion de las plataformas
	const float _gravity = 0.5f;// Aceleración de la gravedad
	static const int NUM_TURTLES_PER_PLATFORM = 4;
	static const int NUM_PLATFORMS = 7;

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

	// Tortugas
	// Restamos una plataforma para que no haya tortugas en el piso
	Turtle* _turtles[NUM_PLATFORMS - 1][NUM_TURTLES_PER_PLATFORM];

	// Métodos privados
	void DoEvents();// Maneja los eventos
	void InitMario();// Inicializa a Mario
	void InitTurtles();// Imicia tortugas
	void UpdateTurtles(float deltaTime);
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

	// Método público
	void Loop();// Bucle principal del juego
};