#include "Cargador.h"


Cargador::Cargador(Juego* pJuego, SDL_Rect Camera, int ancho, int alto, int posX, int posY) : Interfaz(pJuego, Camera, ancho, alto, posX, posY)
{
	textura = pJuego->getTextura(Juego::TCargador);
	distX = 1280;
	distY = 630;
}


Cargador::~Cargador()
{
}
void Cargador::update(SDL_Rect Camera, int contador){
	pRect.x = Camera.x + distX;
	pRect.y = Camera.y + distY;
}
