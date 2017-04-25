#pragma once
#include "ObjetoJuego.h"
#include "SDL.h"
#include "Play.h"

class Objeto : public ObjetoJuego
{
public:
	Objeto(Juego* ptr, int px, int py);
	virtual ~Objeto();

	bool dentro(int x, int y) const; //(A LO MEJOR ES NECESARIO)
	void draw() const;
	bool onClick();
	SDL_Rect getRect();

	void gestorVida() {};
	void onCollision() {};

	collision getType() {
		return tipo;
	}

	bool isDead() {
		return dead;
	}
protected:
	void Oscilar(int delta);
	Juego* juego;
	Textura* textura;
	SDL_Renderer* pRenderer;

	SDL_Rect rect; //Cuadrado en el que se va a dibujar el objeto
	SDL_Rect rectCollision;

	collision tipo;
	bool dead = false;
	bool inmunidad;
	int velX, velY;	//Velocidad del objeto
	//int h, w; // tamaño (ya va en el rect)
	int vida;
	//Para oscilar
	int cont;
	int cont2;
	bool arriba = true;
};

