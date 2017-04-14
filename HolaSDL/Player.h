#pragma once
#include "Objeto.h"

class Player : public Objeto 
{
public:
	Player(Juego* ptr, int px, int py);
	~Player();

	void update(int delta);
	bool onClick();
	void getPos(int& x, int& y);


	void onCollision(collision c);

private:
	int velX, velY;
};

