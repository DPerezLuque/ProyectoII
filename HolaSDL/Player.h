#pragma once
#include "Objeto.h"

//Enumerado de estados del jugador0 
enum EstJugador { QUIETO= 0, ANDANDO = 1, DASH = 3 };
enum direccionesJugador { NoDir, Norte = 270, NorEste = 45, Este = 0, SurEste = 315, Sur = 90, SurOeste = 225, Oeste = 180, NorOeste = 135 };				//Direcciones del jugador para el ángulo

class Player : public Objeto 
{
public:
	Player() {};
	Player(Juego* ptr, int px, int py);
	~Player();

	void update(int delta);
	//void move();
	bool onClick();
	void movimientoDown(SDL_Event evento);
	void movimientoUp(SDL_Event evento);
	//void resetPlayerVel();



private:

	//Variables de movimiento
	direccionesJugador direccion;	//El ángulo del jugador, para eñ movimiento
	int modulo_vel;			//Determina la velocidad del jugador
	//

	EstJugador estJugador;
	SDL_Event evento;
	SDL_TimerID tiempoMaxDash;
};

