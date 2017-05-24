#pragma once
#include "Objeto.h"

class Key: public Objeto
{
public:
	Key(Juego* ptr, int px, int py);
	~Key();
	void destruyeAlma();

	void onCollision(collision type);

	void update(int delta);
private:
	int topeUp, topeDown, contDestruccion;
};

