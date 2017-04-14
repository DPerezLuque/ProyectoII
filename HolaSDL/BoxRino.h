#pragma once
#include "Objeto.h"
class BoxRino : public Objeto
{
public:
	BoxRino(Juego* ptr, int px, int py);
	~BoxRino();
	void update(int delta);
	void onCollision(collision c);
};

