#pragma once
#include "enemigoBase.h"

class enemigoGuardia : public enemigoBase
{
public:
	enemigoGuardia(Juego* ptr, int px, int py);
	~enemigoGuardia();

	void update(int delta);

	virtual void animacionBasica();

private:
	enum animacion {ABAJO, ARRIBA, DERECHA, IZQUIERDA}; //Nos dice qu� animaci�n tiene que hacer
	animacion est;
	void animar(animacion current);
};

