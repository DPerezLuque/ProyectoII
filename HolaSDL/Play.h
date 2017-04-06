#pragma once
#include "Estado.h"

class Play : public Estado
{
public:

	Play(Juego* ptr);
	virtual ~Play();

	void init();
	void onClick();
	void update(int delta);

	void newDisparo(ObjetoJuego*po, int posX, int posY);
	void newDisparoEnemigo(int posX, int posY, int targetX, int targetY, int velDis);
	void posPlayer(int& x, int& y);
private:

	bool gameOver;
};

