#include "BarraVida.h"


BarraVida::BarraVida(Juego* pJuego, Player* jugador, SDL_Rect Camera, int ancho, int alto, int posX, int posY) : Interfaz(pJuego, jugador, Camera, ancho, alto, posX, posY)
{
	//Misma constructora que interfaz
	textura = pJuego->getTextura(Juego::TVidaLlena);
	distX = 15;
	distY = 15;	
	rectAnim = { 0, 0, 128, 32 };
	pRect = rectAnim;

	contador = player->getVida();
}


BarraVida::~BarraVida()
{
}
void BarraVida::draw() const{
	textura->drawAnimacion(pRenderer, pRect, rectAnim);
}

void BarraVida::update(){ 
	//pRect.x = Camera.x + distX;
	//pRect.y = Camera.y + distY;
	contador = player->getVida();

	if (contador > 0){ //4 vidas máx
		rectAnim.w = 32*contador;
		pRect.w = 32 * contador;
	}
	else {
		rectAnim.w = 0; //Muerto, se muestra la vacia
	}	
}
