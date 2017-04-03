#pragma once
#include "Objeto.h"

enum PlayerMovement {QUIETO, ANDANDO, DASHEANDO};

class Player : public Objeto 
{
public:
	Player() {};
	Player(Juego* ptr, int px, int py);
	~Player();

	void update();
	//void move();
	bool onClick();
	void movimientoYDash(SDL_Event evento);
	
protected:

	SDL_Event evento;
};

