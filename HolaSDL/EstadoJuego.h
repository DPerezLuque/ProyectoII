#pragma once
#include "SDL.h"

class EstadoJuego
{
public:

	EstadoJuego() {}
	virtual ~EstadoJuego(){}

	virtual void draw() = 0;

	virtual void update() = 0;

	virtual void onClick() = 0;

	virtual void handleEvent(SDL_Event e) = 0;
};

