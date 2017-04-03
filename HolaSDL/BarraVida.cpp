#include "BarraVida.h"


BarraVida::BarraVida(Juego* pJuego, SDL_Rect Camera, int ancho, int alto) : Interfaz(pJuego, Camera, ancho, alto)
{
	//Misma constructora que interfaz
	distX = 15;
	distY = 15;
}


BarraVida::~BarraVida()
{
}

void BarraVida::update(SDL_Rect Camera, int contador){ //Hay que pasarle la camara y el numero de vidas
	pRect.x = Camera.x + distX;
	pRect.y = Camera.y + distY;

	if (contador > 0){ //4 vidas máx
		pRect.w = 32*contador;
	}
	else {
		pRect.w = 0; //Muerto, se muestra la vacia
	}	

}
