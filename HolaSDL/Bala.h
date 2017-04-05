#pragma once
#include "Objeto.h"

class Bala : public Objeto
{
public:
	Bala(Juego* ptr, int px, int py, int vX, int vY);
	~Bala();

	virtual void update() {};


	void onCollision();
};

