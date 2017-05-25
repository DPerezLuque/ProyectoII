#pragma once
#include "enemigoBase.h"
class Spider : public enemigoBase
{
public:
	Spider(Juego* ptr, int px, int py);
	Spider(Juego* ptr, int px, int py, bool drop);
	~Spider();

	//Métodos heredados de EnemigoBase
	virtual void animacionBasica();			//Animación de la Spider
	virtual void update(int delta);			//Se mueve y dispara al jugador si está a tiro
	virtual void gestorVida();				//Se redefine para que spawnee Spiders pequeñas (porque estoy enfermo)
};

