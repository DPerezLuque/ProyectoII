#pragma once
#include "Interfaz.h"
#include "SDL.h"
class BarraVida : public Interfaz
{
public:
	BarraVida(Juego* pJuego, Player* jugador, SDL_Rect Camera, int ancho, int alto, int posX, int posY);
	virtual ~BarraVida();
	void update(SDL_Rect Camera);	
	void draw() const;
private:
	SDL_Rect rectAnim;
};

