#pragma once
#include "Interfaz.h"
#include "Texto.h"

class Cargador :public Interfaz
{
public:
	Cargador(Juego* pJuego, Player* jugador, int ancho, int alto, int posX, int posY);
	virtual ~Cargador();
	void update();
	void draw() const;
private:
	Texto* fuenteCargador;
	Textura* mensaje;
	SDL_Color Black;
	SDL_Color Red;
};

