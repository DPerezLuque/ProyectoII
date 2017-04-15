#include "Cargador.h"


Cargador::Cargador(Juego* pJuego, SDL_Rect Camera, int ancho, int alto, int posX, int posY) : Interfaz(pJuego, Camera, ancho, alto, posX, posY)
{
	textura = pJuego->getTextura(Juego::TCargador);
	pRect.x = posX;
	pRect.y = posY;
}


Cargador::~Cargador()
{
}
