#pragma once
#include "Estado.h"
#include "Player.h"

class EscenaFinal : public Estado
{
public:
	EscenaFinal(Juego* ptr);
	~EscenaFinal();

	virtual void draw();

	virtual void update(double delta);


private:
	enum estadoCinemática {AvanceAlDialogo, Dialogo, Salida};
	estadoCinemática estCinematica;

	Textura* fondo;
	SDL_Rect dimensionesFondo;

	Textura* cientifico;
	SDL_Rect dimensionesCientifico;
	
	Player* jugador;


};



