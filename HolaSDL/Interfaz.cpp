#include "Interfaz.h"

Interfaz::Interfaz(Juego* juego, SDL_Rect Camera, int ancho, int alto, int posX, int posY)
{
	pJuego = juego;
	pRect = Camera;
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

void Interfaz::update(SDL_Rect Camera, int contador){
	//pRect.x = Camera.x + distX;
	//pRect.y = Camera.y + distY;
}