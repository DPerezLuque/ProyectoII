#pragma once
#include "enemigoBase.h"
class EnemigoPlanta : public enemigoBase
{
public:
	EnemigoPlanta(Juego* ptr, int px, int py);
	~EnemigoPlanta();

	
	void update(int delta);
	void animacionBasica();
};

