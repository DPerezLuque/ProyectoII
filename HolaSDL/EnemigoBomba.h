#pragma once
#include "EnemigoBase.h"

class EnemigoBomba : public EnemigoBase
{
public:
	EnemigoBomba(Juego* ptr, int px, int py);
	~EnemigoBomba();
	
	virtual void animacionBasica();
	virtual void update(int delta);
	
};

