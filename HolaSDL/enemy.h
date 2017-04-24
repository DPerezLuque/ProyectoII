#pragma once
#include "Objeto.h"
#include "BalaEnemigo.h"

class enemy : public Objeto
{
public:
	enemy(Juego* ptr, int px, int py);
	~enemy();

	void update(int delta);
	void follow(int x, int y, float delta);
	void shoot(int x, int y);
	void draw() const;

	void onCollision();
	void onCollision(ObjetoJuego * colisionado);
	void gestorVida(int &vida);

protected:
	int vX, vY;
	int vel; //velocidad del monimiento
	int contDis = 0;
	int freDis; //frecuencia con la que dispara
	int velDis; //velocidad del disparo

	bool inmunidad; //Booleano que se activa cuando toca un enemigo para que no reste la vida de golpe
	int contInm; //Contador inmunidad

	Textura* barraVida;
	SDL_Rect rectVida;
	SDL_Rect rectVidaAux;
};

