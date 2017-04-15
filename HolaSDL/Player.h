#pragma once
#include "Objeto.h"

const int VIDAMAX = 4; //vida máxima del jugador


class Player : public Objeto 
{
public:
	Player(Juego* ptr, int px, int py);
	~Player();

	void update(int delta);
	bool onClick();
	void getPos(int& x, int& y);


	void onCollision();

private:
	int velX, velY;
	int vidaActual; //Vida actual
	bool inmunidad; //Booleano que se activa cuando toc a un enemigo para que no reste la vida de golpe
	int contadorInmunidad; //Contador del tiempo de inmunidad
};

