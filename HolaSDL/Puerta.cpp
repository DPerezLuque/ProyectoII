#include "Puerta.h"


Puerta::Puerta(Juego* ptr, int px, int py, int ancho, int alto) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TBloqueo);
	tipo = PUERTA;
	rect.w = ancho;
	rect.h = alto;
		
	rectCollision = rect;
}


Puerta::~Puerta()
{
}

void Puerta::onCollision(){}