#pragma once
#include "Interfaz.h"
#include "SDL.h"
class BarraVida : public Interfaz
{
public:
	BarraVida(Juego* pJuego, SDL_Rect Camera, int alto, int ancho);
	virtual ~BarraVida();
	void update(SDL_Rect Camera, int contador);	
};

