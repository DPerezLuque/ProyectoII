#pragma once
#include "Objeto.h"

class ExplosionEnemigoB : public Objeto
{
public:
	ExplosionEnemigoB(Juego* ptr, int px, int py);
	~ExplosionEnemigoB();

	void update(int delta);
	void animacionBasica();
	void compruebaColisiones();

private:
	int autodestr;		//Tiempo que tarda la bala en autodestruirse
	int contAutodestr;	//Contador del tiempo de autodestrucción
};
