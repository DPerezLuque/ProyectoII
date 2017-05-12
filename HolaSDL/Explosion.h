#pragma once
#include "Objeto.h"

class Explosion : public Objeto
{
public:
	Explosion(Juego* ptr, int px, int py);
	~Explosion();

	void update(int delta);
	void animacionBasica();

private:
	int autodestr;		//Tiempo que tarda la bala en autodestruirse
	int contAutodestr;	//Contador del tiempo de autodestrucción
};
