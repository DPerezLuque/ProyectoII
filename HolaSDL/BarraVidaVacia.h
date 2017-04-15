#pragma once
#include "Interfaz.h"
#include "SDL.h"
class BarraVidaVacia : public Interfaz
{
public:
	BarraVidaVacia(Juego* pJuego, SDL_Rect Camera, int ancho, int alto, int posX, int posY);
	virtual ~BarraVidaVacia();
	//void update(); //Aqui el contador no vale pa nah
};

