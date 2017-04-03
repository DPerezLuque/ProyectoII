#include "Cargador.h"


Cargador::Cargador(Juego* pJuego, SDL_Rect Camera, int ancho, int alto) : Interfaz(pJuego, Camera, ancho, alto)
{
	distX = 750; //Sobre 860
	distY = 380; //Sobre 480
}


Cargador::~Cargador()
{
}
