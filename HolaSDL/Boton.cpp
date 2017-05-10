#include "Boton.h"

Boton::Boton(Juego* ptr, int px, int py, Juego::Texturas_t tex, collision type) : Objeto(ptr, px, py)
{
	tipo = type;
	//cbOnClick = cb;
	textura = juego->getTextura(tex);
	//visible = true;

	rect.w = 300;
	rect.h = 33;

	rectCollision = rect;
}


Boton::~Boton() {}





