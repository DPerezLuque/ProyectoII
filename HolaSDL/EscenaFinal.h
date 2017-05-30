#pragma once
#include "Estado.h"
#include "Player.h"
#include "Dialogo.h"

class EscenaFinal : public Estado
{
public:
	EscenaFinal(Juego* ptr);
	~EscenaFinal();

	virtual void draw();

	virtual void update();


private:
	enum estadoCinematica {AvanceAlDialogo, Textos, Salida};
	estadoCinematica estCinematica;

	Textura* fondo;
	SDL_Rect dimensionesFondo;

	Textura* cientifico;
	SDL_Rect dimensionesCientifico;
	
	Player* jugador;

	Dialogo* mensaje;

	int contMensajes; //Cuenta en qu� mensaje est�
	int contTiempo;
	bool creaMensaje;
	bool pintaMensaje;

	
};



