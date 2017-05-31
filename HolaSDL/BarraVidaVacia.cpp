#include "BarraVidaVacia.h"
#include "Juego.h"

BarraVidaVacia::BarraVidaVacia(Juego* pJuego, ObjetoJuego* jugador, int ancho, int alto, int posX, int posY) : Interfaz(pJuego, jugador, ancho, alto, posX, posY)
{
	//Misma constructora que interfaz
	textura = pJuego->getTextura(Juego::TVidaVacia);
	filtro = pJuego->getTextura(Juego::TFiltro);
	rectangulo = { 0, 0, pJuego->getWidth(), pJuego->getHeight() };
	distX = 15;
	distY = 15;
}


BarraVidaVacia::~BarraVidaVacia()
{
}

void BarraVidaVacia::draw() const {
	if (pJuego->getFiltro()){
		filtro->draw(pRenderer, 0, 0, rectangulo);
	}

	textura->draw(pRenderer, pRect.x, pRect.y, pRect);
}
