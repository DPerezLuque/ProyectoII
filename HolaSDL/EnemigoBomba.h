#pragma once
#include "enemigoBase.h"

class EnemigoBomba : public enemigoBase
{
public:
	EnemigoBomba(Juego* ptr, int px, int py);
	~EnemigoBomba();
	
	virtual void animacionBasica();
	virtual void update(int delta);
	
};

