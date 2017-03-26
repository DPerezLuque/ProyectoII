#pragma once
#include "SDL.h"

const int DASH = 30;
const int VPLAYER = 10;
class Juego;


class MovimientoJugador 
{
public:
	MovimientoJugador(Juego * game);
	~MovimientoJugador();
	void setMovimientoJugador (SDL_Event e);
	void getMovimientoJugador(int & newVelX, int & newVelY);
	MovimientoJugador * setPunteroMovimiento(MovimientoJugador*) {
		
	}
private:
	int velX, velY;
	Juego * juego;
};

