#pragma once
#include "Estado.h"
class MenuFinalJuego : public Estado
{
public:
	MenuFinalJuego(Juego* ptr);
	~MenuFinalJuego();

	void draw();
private:
	Textura* logo;
	SDL_Rect tamano;
};

