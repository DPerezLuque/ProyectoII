#pragma once
#include "enemigoBase.h"

class Ara�ita : public enemigoBase
{
public:
	Ara�ita(Juego* ptr, int px, int py);
	~Ara�ita();

	//M�todos heredados de EnemigoBase
	virtual void animacionBasica();			//Animaci�n de la ara�a
	virtual void update(int delta);			//Se mueve y dispara al jugador si est� a tiro
	//M�todos propios
	pair <int, int> nuevaPosicion();
private:
	int contadorMovimiento;
	bool actualizaMov;

	pair <int, int> pos;
};

