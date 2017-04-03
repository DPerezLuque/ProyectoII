#include "BarraVidaVacia.h"


BarraVidaVacia::BarraVidaVacia(Juego* pJuego, SDL_Rect Camera, int ancho, int alto) : Interfaz(pJuego, Camera, ancho, alto)
{
	//Misma constructora que interfaz
	distX = 15;
	distY = 15;
}


BarraVidaVacia::~BarraVidaVacia()
{
}
