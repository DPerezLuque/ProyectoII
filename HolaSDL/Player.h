#pragma once
#include "Objeto.h"

class Player : public Objeto 
{
public:
	Player(Juego* ptr, int px, int py);
	~Player();

	void update();
	bool onClick();
	void getPos(int& x, int& y);
	int getVida(){ return vida; }

private:
	int velX, velY;
	int vida;
};

