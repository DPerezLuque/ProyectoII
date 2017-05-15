#pragma once
#include "Interfaz.h"
#include "SDL.h"
class BarraVidaVacia : public Interfaz
{
public:
	BarraVidaVacia(Juego* pJuego, ObjetoJuego* jugador, int ancho, int alto, int posX, int posY);
	virtual ~BarraVidaVacia();
	void update(){}
};

