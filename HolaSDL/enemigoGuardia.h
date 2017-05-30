#pragma once
#include "EnemigoBase.h"

class EnemigoGuardia : public EnemigoBase
{
public:
	EnemigoGuardia(Juego* ptr, int px, int py);
	~EnemigoGuardia();

	void update(int delta);

	virtual void animacionBasica();

private:
	enum animacion {ABAJO, ARRIBA, DERECHA, IZQUIERDA}; //Nos dice qué animación tiene que hacer
	animacion est;
	void animar(animacion current);
};

