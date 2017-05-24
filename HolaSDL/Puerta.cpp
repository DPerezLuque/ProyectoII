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

void Puerta::onCollision(collision type){
	if (juego->tieneLlave){
		juego->quitaLlave();
		dead = true;
	}
}

void Puerta::update(int delta){
	if (juego->tieneLlave){
		textura = juego->getTextura(Juego::TBloqueo2);
	}
	else textura = juego->getTextura(Juego::TBloqueo);
}