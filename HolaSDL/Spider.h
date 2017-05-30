#pragma once
#include "EnemigoBase.h"
class Spider : public EnemigoBase
{
public:
	Spider(Juego* ptr, int px, int py);
	Spider(Juego* ptr, int px, int py, bool drop);
	~Spider();

	//M�todos heredados de EnemigoBase
	virtual void animacionBasica();			//Animaci�n de la Spider
	virtual void update(int delta);			//Se mueve y dispara al jugador si est� a tiro
	virtual void gestorVida();				//Se redefine para que spawnee Spiders peque�as (porque estoy enfermo)
};

