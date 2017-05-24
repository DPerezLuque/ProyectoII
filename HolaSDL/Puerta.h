#pragma once
#include "Objeto.h"

class Puerta : public Objeto
{
public:
	Puerta(Juego* ptr, int px, int py, int ancho, int alto);
	~Puerta();
	void onCollision(collision type);
	void update(int delta);

};

