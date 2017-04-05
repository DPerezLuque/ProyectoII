#pragma once
#include "HUD.h"
#include "SDL.h"
#include "Textura.h"
#include "Play.h"

class Interfaz : public HUD
{
public:
	Interfaz(Juego* pJuego, SDL_Rect Camera, int ancho, int alto);
	virtual ~Interfaz();

	void draw() const;
	void update(SDL_Rect Camera, int contador); //Se encargar� de actualizar el contador, el ancho y el alto en proporcion

protected:
	Juego* pJuego;
	SDL_Rect pRect; //Donde se dibujar� el elemento
	SDL_Renderer* pRenderer;
	Textura* textura;

	int distX, distY; //Distancia respecto la c�mara

};

