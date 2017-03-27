#pragma once
#include "SDL.h"
//#include "Player.h"

const int DASH = 30;
const int VPLAYER = 10;



class MovimientoJugador //: public Player
{
public:
	MovimientoJugador();
	~MovimientoJugador();
	void setMovimientoJugador (SDL_Event e);
	void getMovimientoJugador(int & newVelX, int & newVelY);
	MovimientoJugador * setPunteroMovimiento() {
		
	}
private:
	int velX, velY;
	
};

