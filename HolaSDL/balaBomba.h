#pragma once
#include "Bala.h"
class balaBomba : public Bala
{
public:
	balaBomba(Juego* ptr, int px, int py, int vX, int vY);
	~balaBomba();
	
	virtual void update(int delta);

	void explosionBala();

private:
	SDL_Rect rectAnim;		//Rectangulo para la animación, si hubiera
	int contadorFrames;		//Para el paso de frames de la animación
};

