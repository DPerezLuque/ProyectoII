#pragma once
#include "Objeto.h"

//Enumerado de estados del jugador
enum EstJugador {QUIETO, ANDANDO, DASHEANDO};
const int DASH = 30;	//Dash del jugador
const int VPLAYER = 10; //Velocidad jugador

class Player : public Objeto 
{
public:
	Player() {};
	Player(Juego* ptr, int px, int py);
	~Player();

	void update();
	//void move();
	bool onClick();
	void movimientoDown(SDL_Event evento);
	void movimientoUp(SDL_Event evento);
	void resetPlayerVel();
protected:

	EstJugador estJugador;
	SDL_Event evento;
	SDL_TimerID tiempoMaxDash;
};

