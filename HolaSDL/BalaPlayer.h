#pragma once
#include "Bala.h"
class BalaPlayer : public Bala
{
public:
	BalaPlayer(Juego* ptr, int px, int py, int vX, int vY);
	~BalaPlayer();

	void update(int delta);

	//void onCollision(int vida, collision tipo);

};
