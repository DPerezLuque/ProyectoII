#include "BarraVidaVacia.h"


BarraVidaVacia::BarraVidaVacia(Juego* pJuego, SDL_Rect Camera, int ancho, int alto, int posX, int posY) : Interfaz(pJuego, Camera, ancho, alto, posX, posY)
{
	//Misma constructora que interfaz
	textura = pJuego->getTextura(Juego::TVidaVacia);
	distX = 15;
	distY = 15;
}


BarraVidaVacia::~BarraVidaVacia()
{
}

void BarraVidaVacia::update(SDL_Rect Camera, int contador){
//	pRect.x = Camera.x + distX;
	//pRect.y = Camera.y + distY;
}
