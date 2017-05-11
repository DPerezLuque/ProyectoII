#pragma once
#include "Bala.h"
class balaBomba : public Bala
{
public:
	balaBomba(Juego* ptr, int px, int py, int vX, int vY);
	~balaBomba();
	//Método de Bala
	virtual void update(int delta);
	//Metodos propios
	void explosionBala();
	void animacionBasica();

private:
	int contadorFrames;		//Para el paso de frames de la animación
};

