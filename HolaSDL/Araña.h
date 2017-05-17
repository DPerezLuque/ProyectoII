#pragma once
#include "enemigoBase.h"
class Araña : public enemigoBase
{
public:
	Araña(Juego* ptr, int px, int py);
	~Araña();

	//Métodos heredados de EnemigoBase
	virtual void animacionBasica();			//Animación de la araña
	virtual void update(int delta);			//Se mueve y dispara al jugador si está a tiro
	virtual void gestorVida();				//Se redefine para que spawnee arañas pequeñas (porque estoy enfermo)
};

