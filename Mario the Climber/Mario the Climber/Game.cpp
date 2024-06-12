#include "Game.h"

Game::Game()
{

	// Inicialización de la ventana y parámetros de juego
	_wnd = new RenderWindow(VideoMode(800, 600), "Mario the Climber");
	_wnd->setFramerateLimit(60);
	_gameOver = false;
	_youWin = false;

	// Inicialización del fondo
	_backTx = new Texture;
	_backSp = new Sprite;
	_backTx->loadFromFile("Asset/Images/fondo_plataformas.png");
	_backSp->setTexture(*_backTx);

	// Inicialización de Mario
	InitMario();
}

void Game::DoEvents()
{

	// Maneja los eventos del teclado (movimiento de Mario)
	Event e;// Crea un objeto Event para procesar los eventos
	while (_wnd->pollEvent(e))// Recorre los eventos ocurridos en la ventana
	{

		if (e.type == Event::Closed)
			_wnd->close();

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			_runningLeft = true;
			_runningRight = false;
			_mario->Play("run");
			_mario->FlipX(false);
			float _newPos = _mario->getPosition().x - 25;// Calcula la nueva posición de Mario en el eje X
			if (_newPos >= _w_x_min)// Si la nueva posición no sale de la pantalla por el lado izquierdo
			{
				_mario->move(-_velocity.x, 0);
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::D))
		{
			_runningRight = true;
			_runningLeft = false;
			_mario->Play("run");
			_mario->FlipX(true);
			float _newPos = _mario->getPosition().x + 25;// Calcula la nueva posición de Mario en el eje X

			if (_newPos <= _w_x_max)// Si la nueva posición no sale de la pantalla por el lado derecho
			{
				_mario->move(_velocity.x, 0);
			}
		}
		else {
			//descanso
			_runningLeft = false;
			_runningRight = false;
			_mario->Play("idle");
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Space) && !_isJumping)// Si se presiona la tecla 'Espacio' y Mario no está saltando
	{
		//salto
		_isJumping = true;
		_velocity.y = -10.f;
		_mario->Play("jump");
		//_audio->PlayJump();
	}
	if (_isJumping)// Si Mario está saltando
	{
		_velocity.y += _gravity;
		_mario->move(0, _velocity.y);

		if (_mario->getPosition().y >= _floor)
		{
			//piso
			_mario->setPosition(Vector2f(_mario->getPosition().x, _floor));// Coloca a Mario sobre el piso
			_isJumping = false;// Establece que Mario ya no está saltando
			_velocity.y = -10.f;// Reinicia la velocidad vertical inicial para el salto
		}
	}
	if (e.key.code == Keyboard::R) { _wnd->close(); new Game; };//reiniciar juego
}


void Game::Loop()
{

	// Bucle principal del juego
	while (_wnd->isOpen())
	{
		if (!_gameOver && !_youWin)
		{
			_wnd->setMouseCursorVisible(false);// Oculta el cursor del mouse
			DoEvents();
			DrawGame();
			_mario->Update();
			ProcessCollision();
			CheckGameConditions();
		}
		else
		{
			GameOver();
		}
	}
}

void Game::InitMario()
{

	// Inicialización de Mario
	_marioTex = new Texture;// Crear un objeto Texture para las animaciones de Mario
	_marioTex->loadFromFile("Asset/Images/spriteSheetMario.png");// Cargar la hoja de sprites de Mario
	_mario = new Afichmation(*_marioTex, true, 208, 249);// Crear un objeto Afichmation para Mario
	_mario->Add("idle", { 0, 1, 2, 1, 0 }, 8, true);// Agregar la animación de descanso
	_mario->Add("run", { 3, 4, 5, 4 }, 8, true);// Agregar la animación de correr
	_mario->Add("jump", { 14 }, 8, true);// Agregar la animación de salto
	_mario->Play("idle");// Establecer la animación inicial en "idle"
	_mario->setScale(Vector2f(0.20f, 0.20f));// Escalar el sprite de Mario a un 20% de su tamaño
	_mario->setOrigin(_mario->getOrigin().x / 2, _mario->getGlobalBounds().height - 16);// Establece el origen en el centro del ancho y 16 pixeles en alto
	_mario->setPosition(Vector2f(50.f, 480.f));// Posicion inicial en x e y
	_mario->FlipX(true);// Comienza el sprite mirando a la derecha
	_velocity = Vector2f(5.f, 0.f);// Setear la velocidad x en 5 (es constante)
	_isJumping = false;
	_runningLeft = false;
	_runningRight = false;
}

void Game::ProcessCollision()
{
}

void Game::CheckGameConditions()
{
}

void Game::GameOver()
{
}

void Game::DrawGame()
{
	//Limpia la ventana, dibuja y muestra todos los elementos
	_wnd->clear();
	_wnd->draw(*_backSp);
	_wnd->draw(*_mario);
	_wnd->display();
}

Game::~Game()
{

	// Liberación de recursos
	delete _backSp;
	delete _mario;
}