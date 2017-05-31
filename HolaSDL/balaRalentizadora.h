#pragma once
#include "Bala.h"

class BalaRalentizadora : public Bala
{
public:
	BalaRalentizadora(Juego* ptr, int px, int py, int vX, int vY);
	~BalaRalentizadora();
	//Método de Objeto
	//virtual void onCollision(collision);
	//Método de Bala
	//virtual void update(int delta);		De momento como no tiene animación, que se mueva como una bala normal
};

