#pragma once
#include "Objeto.h"

class Puerta : public Objeto
{
public:
	Puerta(Juego* ptr, int px, int py, int ancho, int alto);
	~Puerta();
	void onCollision();
	void update(int delta){}

};

