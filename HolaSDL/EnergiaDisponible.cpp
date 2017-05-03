#include "EnergiaDisponible.h"


EnergiaDisponible::EnergiaDisponible(Juego* pJuego, SDL_Rect Camera, int ancho, int alto, int posX, int posY) : Interfaz(pJuego, Camera, ancho, alto, posX, posY)
{
	//Misma constructora que interfaz
	textura = pJuego->getTextura(Juego::TDashLleno); 
	textura2 = pJuego->getTextura(Juego::TDashVacio);
	distX = 30;
	distY = 40;	
	pRect = { distX, distY, 39, 40 };
}


EnergiaDisponible::~EnergiaDisponible()
{
}

void EnergiaDisponible::update(SDL_Rect Camera, int contador){
	if (contador == 0){
		activo = true;
	}
	else{ activo = false; }
}

void EnergiaDisponible::draw() const{
	if (activo){
		textura->draw(pRenderer, pRect.x, pRect.y, pRect);
	}
	else{
		textura2->draw(pRenderer, pRect.x, pRect.y, pRect);
	}	
}
