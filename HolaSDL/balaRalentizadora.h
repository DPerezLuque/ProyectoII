#pragma once
#include "Bala.h"

class BalaRalentizadora : public Bala
{
public:
	BalaRalentizadora(Juego* ptr, int px, int py, int vX, int vY);
	~BalaRalentizadora();
	//M�todo de Objeto
	//virtual void onCollision(collision);
	//M�todo de Bala
	//virtual void update(int delta);		De momento como no tiene animaci�n, que se mueva como una bala normal
};

