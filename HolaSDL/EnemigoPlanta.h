#pragma once
#include "enemy.h"
class EnemigoPlanta : public enemy
{
public:
	EnemigoPlanta(Juego* ptr, int px, int py);
	~EnemigoPlanta();

	void update(int delta);
};

