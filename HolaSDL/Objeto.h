#pragma once
#include "ObjetoJuego.h"
#include "SDL.h"
#include "Play.h"

class Objeto : public ObjetoJuego
{
public:
	Objeto() {};
	Objeto(Juego* ptr, int px, int py);
	virtual ~Objeto();

	bool dentro(int x, int y) const; //(A LO MEJOR ES NECESARIO)
	void draw() const;
	bool onClick();

protected:

	Juego* juego;
	Play* play;
	Textura* textura;
	SDL_Renderer* pRenderer;

	SDL_Rect rect; //Cuadrado en el que se va a dibujar el objeto

	int velX, velY;
	int h, w; // tamaño
			  //bool visible; (ESTO A LO MEJOR ES UTIL PARA HACER INVISIBLE A LOS ENEMIGOS CUANDO MUERAN)
};

