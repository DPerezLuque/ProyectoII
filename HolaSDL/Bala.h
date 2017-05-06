#pragma once
#include "Objeto.h"

class Bala : public Objeto
{
public:
	Bala(Juego* ptr, int px, int py, int vX, int vY);
	~Bala();

	int cont;	
	int autodestr;	//Tiempo que tarda la bala en autodestruirse

	void update(int delta);

	void onCollision(collision type);

};

