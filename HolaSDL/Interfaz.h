#pragma once
#include "HUD.h"
#include "SDL.h"
#include "Textura.h"
#include "Play.h"

class Interfaz : public HUD
{
public:
	Interfaz(Juego* pJuego, SDL_Rect Camera, int ancho, int alto, int posX, int posY);
	virtual ~Interfaz();

	void draw() const;
	virtual void update(SDL_Rect Camera, int contador) = 0; //Se encargará de actualizar el contador, el ancho y el alto en proporcion

protected:
	Juego* pJuego;
	SDL_Rect pRect; //Donde se dibujará el elemento
	SDL_Renderer* pRenderer;
	Textura* textura;

	int distX, distY; //Distancia respecto la cámara

};

