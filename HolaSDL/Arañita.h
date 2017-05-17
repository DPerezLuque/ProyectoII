#pragma once
#include "enemigoBase.h"

class Arañita : public enemigoBase
{
public:
	Arañita(Juego* ptr, int px, int py);
	~Arañita();

	//Métodos heredados de EnemigoBase
	virtual void animacionBasica();			//Animación de la araña
	virtual void update(int delta);			//Se mueve y dispara al jugador si está a tiro

private:
	int contadorMovimiento;
};

