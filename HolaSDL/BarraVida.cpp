#include "BarraVida.h"


BarraVida::BarraVida(Juego* pJuego, ObjetoJuego* jugador, int ancho, int alto, int posX, int posY) : Interfaz(pJuego, jugador, ancho, alto, posX, posY)
{
	//pJuego->player->getStats(vida, balas, contador);

	//Misma constructora que interfaz
	textura = pJuego->getTextura(Juego::TVidaLlena);
	distX = 15;
	distY = 15;	
	rectAnim = { 0, 0, 128, 32 };
	pRect = rectAnim;
	juga = jugador;
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
	//contador = juga->getVida();

	if (contador > 0){ //4 vidas máx
		rectAnim.w = 32*contador;
		pRect.w = 32 * contador;
	}
	else {
		rectAnim.w = 0; //Muerto, se muestra la vacia
	}	
}
