#pragma once
#include "Objeto.h"
#include "GestorVida.h"

const int VIDAMAX = 4; //vida máxima del jugador
const int VIDAMIN = 0; //Vida mínima del jugador

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
};

