#include "BarraVidaVacia.h"


BarraVidaVacia::BarraVidaVacia(Juego* pJuego, Player* jugador, int ancho, int alto, int posX, int posY) : Interfaz(pJuego, jugador, ancho, alto, posX, posY)
{
	//Misma constructora que interfaz
	textura = pJuego->getTextura(Juego::TVidaVacia);
	distX = 15;
	distY = 15;
}


BarraVidaVacia::~BarraVidaVacia()
{
}

