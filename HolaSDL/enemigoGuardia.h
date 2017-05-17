#pragma once
#include "enemigoBase.h"

class enemigoGuardia : public enemigoBase
{
public:
	enemigoGuardia(Juego* ptr, int px, int py);
	~enemigoGuardia();

	void update(int delta);
};

