#pragma once
#include "Bala.h"
class BalaBomba : public Bala
{
public:
	BalaBomba(Juego* ptr, int px, int py, int vX, int vY);
	~BalaBomba();
	//Método de Objeto
	virtual void onCollision(collision);
	//Método de Bala
	virtual void update(int delta);
	//Metodos propios
	void explosionBala();
	void animacionBasica();

private:
	int contadorFrames;		//Para el paso de frames de la animación
	
};

