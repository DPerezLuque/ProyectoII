#pragma once
#include "Objeto.h"

class enemy : public Objeto 
{
public:
	enemy(Juego* ptr, int px, int py);
	~enemy();

	void update();
	void follow(int x, int y);
	void shoot(int x, int y);

private:
	int vX, vY;
	int vel; //velocidad del monimiento
	int contDis = 0;
	int freDis; //frecuencia con la que dispara
	int velDis; //velocidad del disparo
};

