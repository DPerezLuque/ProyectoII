#pragma once
#include "enemigoBase.h"

class littleSpider : public enemigoBase
{
public:
	littleSpider(Juego* ptr, int px, int py);
	~littleSpider();

	//M�todos heredados de EnemigoBase
	virtual void animacionBasica();			//Animaci�n de la ara�a
	virtual void update(int delta);			//Se mueve y dispara al jugador si est� a tiro
	//M�todos propios
	void nuevaPosicion();
private:
	int contadorMovimiento, contadorQuieto;
	bool actualizaMov;

	pair <int, int> pos;
	int directionX, directionY;
};

