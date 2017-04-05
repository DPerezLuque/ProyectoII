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
	void newDisparoEnemigo(int posX, int posY, int targetX, int targetY, int velDis);
	void posPlayer(int& x, int& y);
private:
	void getStats(int i);

	bool gameOver;
	Texto textoDePrueba;
	Textura* cosaDePrueba;
	SDL_Color Black;
	SDL_Rect rectamgulon;

	//Stats del jugador (necesarios para la interfaz)
	int vidaAux;
};

