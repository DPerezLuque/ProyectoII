#include "EnergiaDisponible.h"


EnergiaDisponible::EnergiaDisponible(Juego* pJuego, ObjetoJuego* jugador, int ancho, int alto, int posX, int posY) : Interfaz(pJuego, jugador, ancho, alto, posX, posY)
{
	pJuego->player->getStats(vida, balas, contador);

	//Misma constructora que interfaz
	textura = pJuego->getTextura(Juego::TDashLleno); 
	textura2 = pJuego->getTextura(Juego::TDashVacio);
	distX = 15;
	distY = 40;	
	pRect = { distX, distY, 25, 26 };

}

EnergiaDisponible::~EnergiaDisponible()
{
}

void EnergiaDisponible::update(){
//	contador = player->getDash();
	pJuego->player->getStats(vida, balas, contador);

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
