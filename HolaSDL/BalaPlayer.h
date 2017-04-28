#pragma once
#include "Bala.h"
class BalaPlayer : public Bala
{
public:
	BalaPlayer(Juego* ptr, int px, int py, int vX, int vY);
	~BalaPlayer();

	//void onCollision(int vida, collision tipo);
	void onCollision(collision);
};
