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

	vector <string> musicNames;
	Musica* cancion;
	vector <Musica*> musicFiles;

	Efecto* bird;

	int contMensajes; //Cuenta en qué mensaje está
	int contTiempo;
	bool creaMensaje;
	bool pintaMensaje;

	
};



