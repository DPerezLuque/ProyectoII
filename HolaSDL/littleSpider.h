#pragma once
#include "enemigoBase.h"

class littleSpider : public enemigoBase
{
public:
	littleSpider(Juego* ptr, int px, int py);
	~littleSpider();

	//Métodos heredados de EnemigoBase
	virtual void animacionBasica();			//Animación de la Spider
	virtual void update(int delta);			//Se mueve y dispara al jugador si está a tiro
	//Métodos propios
	void nuevaPosicion();
	void miniCarga(int, int, int, int);						//carga contra el jugador a una velocidad más alta que el método "follow"
private:
	int contadorMovimiento, contadorQuieto;
	bool actualizaMov;
	

	pair <int, int> pos;
	int directionX, directionY;
};

