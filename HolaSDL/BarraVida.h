#pragma once
#include "Interfaz.h"
#include "SDL.h"
#include "Player.h"

class BarraVida : public Interfaz
{
public:
	BarraVida(Juego* pJuego, ObjetoJuego* jugador, int ancho, int alto, int posX, int posY);
	virtual ~BarraVida();
	void update();	
	void draw() const;
private:
	SDL_Rect rectAnim;
	ObjetoJuego* juga;
};

