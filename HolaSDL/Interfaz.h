#pragma once
#include "HUD.h"
#include "SDL.h"
#include "Textura.h"
#include "Play.h"
#include "Player.h"

class Interfaz : public HUD
{
public:
	Interfaz(Juego* pJuego, Player* jugador, SDL_Rect Camera, int ancho, int alto, int posX, int posY);
	virtual ~Interfaz();

	void draw() const;
	virtual void update() = 0; //Se encargará de actualizar el contador, el ancho y el alto en proporcion

protected:
	Juego* pJuego;
	Player* player;
	SDL_Rect pRect; //Donde se dibujará el elemento
	SDL_Renderer* pRenderer;
	Textura* textura;
	int contador;
	int distX, distY; //Distancia respecto la cámara

};

