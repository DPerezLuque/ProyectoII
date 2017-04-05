#pragma once
#include "Estado.h"
//#include "Player.h"

class Player;

class Play : public Estado
{
public:

	Play(Juego* ptr);
	virtual ~Play();

	void init();

	virtual void onClick();
	virtual void update();
	void handleEvent(SDL_Event e);
	void getMousePos(int & mpx, int & mpy) const{};

	void newDisparo(ObjetoJuego*po, int posX, int posY);
private:

	bool gameOver;

	Player* player;
};

