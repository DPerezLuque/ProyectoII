#pragma once
#include "Objeto.h"

class Bala : public Objeto
{
public:
	Bala(Juego* ptr, int px, int py, int vX, int vY);
	virtual ~Bala();

	int cont;	
	int autodestr;	//Tiempo que tarda la bala en autodestruirse

	void update(int delta);

	void onCollision(collision type);

	//Redefinimos el draw porque tenemos balas animadas
	virtual void draw() const ;

protected:
	bool balaAnimada;		//Determina si se dibuja est�tica o con animaci�n

	//SDL_Rect rectAnim;		//Rectangulo para la animaci�n, si la necesitamos

};

