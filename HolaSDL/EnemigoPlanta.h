#pragma once
#include "EnemigoBase.h"
class EnemigoPlanta : public EnemigoBase
{
public:
	EnemigoPlanta(Juego* ptr, int px, int py);
	~EnemigoPlanta();
	
	void update(int delta);

	virtual void animacionBasica();
	virtual void follow(int x, int y, float delta){}

};

