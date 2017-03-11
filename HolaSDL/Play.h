#pragma once
#include "Estado.h"

class Play : public Estado
{
public:

	Play(Juego* ptr);
	virtual ~Play();

	void init();
	void onClick();
	void update();

	void newDisparo(ObjetoJuego*po, int posX, int posY);
private:

	bool gameOver;
};

