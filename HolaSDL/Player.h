#pragma once
#include "Objeto.h"

class Player : public Objeto 
{
public:
	Player() {};
	Player(Juego* ptr, int px, int py);
	~Player();

	void update();
	//void move();
	bool onClick();
	void dash();
	
protected:
	int velX, velY;
};

