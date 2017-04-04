#pragma once
#include "Objeto.h"

class Player : public Objeto 
{
public:
	Player(Juego* ptr, int px, int py);
	~Player();

	void update();
	bool onClick();
<<<<<<< HEAD
	void getPos(int& x, int& y);
=======

	void onCollision();
>>>>>>> origin/collisions

private:
	int velX, velY;
};

