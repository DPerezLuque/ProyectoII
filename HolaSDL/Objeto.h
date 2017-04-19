#pragma once
#include "ObjetoJuego.h"
#include "SDL.h"
#include "Play.h"

class Objeto : public ObjetoJuego
{
public:
	Objeto(Juego* ptr, int px, int py);
	virtual ~Objeto();

	virtual void onCollision(ObjetoJuego * colisionado) = 0;

	bool dentro(int x, int y) const; //(A LO MEJOR ES NECESARIO)
	void draw() const;
	bool onClick();
	SDL_Rect getRect();

	void onCollision(int vida, collision tipo);
	void gestorVida(int vida);

	collision getType() {
		return tipo;
	}

	bool isDead() {
		return dead;
	}
protected:
	Juego* juego;
	Textura* textura;
	SDL_Renderer* pRenderer;

	SDL_Rect rect; //Cuadrado en el que se va a dibujar el objeto
	SDL_Rect rectCollision;

	collision tipo;
	bool dead = false;
	int velX, velY;	//Velocidad del objeto
	//int h, w; // tamaño (ya va en el rect)
};

