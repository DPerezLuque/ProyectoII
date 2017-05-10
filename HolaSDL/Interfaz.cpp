#include "Interfaz.h"

Interfaz::Interfaz(Juego* juego, ObjetoJuego* jugador, int ancho, int alto, int posX, int posY)
{
	pJuego = juego;
	player = jugador;
	pRenderer = pJuego->getRender();	

	pRect.x = posX;
	pRect.y = posY;
	pRect.w = ancho; //Propiedades de la textura que cambiarán en funcion de valores del juego (contador), no de la cámara
	pRect.h = alto;
}


Interfaz::~Interfaz()
{
	
}

void Interfaz::draw() const {
	textura->draw(pRenderer, pRect.x, pRect.y, pRect);
}
