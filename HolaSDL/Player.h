#pragma once
#include "Objeto.h"

class Player : public Objeto 
{
public:
	Player(Juego* ptr, int px, int py);
	~Player();

	void update();
	//void move();
	bool onClick();
private:
	int velX, velY;
};

