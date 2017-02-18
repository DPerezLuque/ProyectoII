#pragma once
#include "ObjetoPG.h"

class Personaje: public ObjetoPG
{
public:
	Personaje(juegoPG* pGame);
	~Personaje();
	virtual bool onClick();
	virtual void update();
private:
	void Disparar();

};

