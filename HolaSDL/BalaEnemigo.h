#pragma once
#include "Bala.h"

class BalaEnemigo : public Bala
{
public:
	BalaEnemigo(Juego* ptr, int px, int py, int vX, int vY);
	~BalaEnemigo();


	void update(int delta);

	//void update();

	//void onCollision(int vida, collision tipo);
};

