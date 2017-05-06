#include "BarraVidaVacia.h"


BarraVidaVacia::BarraVidaVacia(Juego* pJuego, Player* jugador, SDL_Rect Camera, int ancho, int alto, int posX, int posY) : Interfaz(pJuego, jugador, Camera, ancho, alto, posX, posY)
{
	//Misma constructora que interfaz
	textura = pJuego->getTextura(Juego::TVidaVacia);
	distX = 15;
	distY = 15;
}


BarraVidaVacia::~BarraVidaVacia()
{
}

