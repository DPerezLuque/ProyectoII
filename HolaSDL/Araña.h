#pragma once
#include "enemigoBase.h"
class Ara�a : public enemigoBase
{
public:
	Ara�a(Juego* ptr, int px, int py);
	~Ara�a();

	//M�todos heredados de EnemigoBase
	virtual void animacionBasica();			//Animaci�n de la ara�a
	virtual void update(int delta);			//Se mueve y dispara al jugador si est� a tiro
	virtual void gestorVida();				//Se redefine para que spawnee ara�as peque�as (porque estoy enfermo)
};

