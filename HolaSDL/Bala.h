#pragma once
#include "Objeto.h"

class Bala : public Objeto
{
public:
	Bala(Juego* ptr, int px, int py, int vX, int vY);
	~Bala();

	void update(int delta);

	//void onCollision(int  vida, collision tipo);

	virtual void onCollision() = 0;

};

