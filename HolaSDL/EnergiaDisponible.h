#pragma once
#include "Interfaz.h"
#include "SDL.h"
#include <vector>

class EnergiaDisponible :
	public Interfaz
{
public:
	EnergiaDisponible(Juego* pJuego, SDL_Rect Camera, int alto, int ancho);
	virtual ~EnergiaDisponible();
	void update(SDL_Rect Camera, int contador);
	void draw(); //Cambiamos el draw, recorrerá el vector de rectangulos y dibujará todos

	int cuenta = 1; //Numero inicial de energia
	vector<SDL_Rect> numEnergias; //En función del número (inicialmente 1) se dibujarán más o menos texturas

};

