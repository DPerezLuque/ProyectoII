#include "Cargador.h"


Cargador::Cargador(Juego* pJuego, Player* jugador, SDL_Rect Camera, int ancho, int alto, int posX, int posY) : Interfaz(pJuego, jugador, Camera, ancho, alto, posX, posY)
{
	textura = pJuego->getTextura(Juego::TCargador);
	//distX = 1280;
	//distY = 630;
}


Cargador::~Cargador()
{
}

void Cargador::update(SDL_Rect Camera){
	///////
}