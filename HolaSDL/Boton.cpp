#include "Boton.h"

Boton::Boton(Juego* ptr, int px, int py, CallBack_t * cb, Juego::Texturas_t tex) : Objeto(ptr, px, py)
{
	cbOnClick = cb;
	textura = juego->getTextura(tex);
	//visible = true;

	rect.w = 150;
	rect.h = 70;
}


Boton::~Boton() {}


bool Boton::onClick()
{	
	if (Objeto::onClick()){
		cbOnClick(juego);
		return true;
	}
	else return false;
}

void Boton::update() {}


