#pragma once
#include "Includes&usings.h"
#include "Afichmation.h"
#include "Animation.h"
#include "Counter.h"
#include "Shell.h"

class Game
{
private:
	// Propiedades relacionadas con el mundo del juego
	const int _w_x_min = 0;// Límite izquierdo de la pantalla
	const int _w_x_max = 800;// Límite derecho de la pantalla
	const int _floor = 480;// Posicion del piso
	const float _gravity = 0.5f;// Aceleración de la gravedad

	// Ventana del juego
	RenderWindow* _wnd;

	// Escenario de fondo
	Texture* _backTx;
	Sprite* _backSp;
	Texture* _doorTx;
	Sprite* _door;

	// Temporizador
	Counter* _timer;

	// Textos y fuente
	Font* _font;
	Text* _gameOverText;

	Shell* _shellStack;
	Sprite* _shellGetToPop;

	// Mario
	Texture* _marioTex;
	Afichmation* _mario;
	Vector2f _velocity;
	bool _isJumping;
	bool _runningLeft;
	bool _runningRight;

	// Métodos privados
	void DoEvents();// Maneja los eventos
	void InitMario();// Inicializa a Mario
	void ProcessCollision();// Procesa las colisiones entre Mario y las tortugas
	void DrawGame();
	void CheckGameConditions();// Verifica las condiciones de victoria o derrota
	void GameOver();// Muestra la pantalla de "Game Over"
	void PushShell(int _x);
	void PopShell();
	void LoadStack();
	void UpdateStack();

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