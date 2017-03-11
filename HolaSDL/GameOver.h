#pragma once
#include "Estado.h"

class GameOver : public Estado
{
public:
	GameOver(Juego* ptr, int p);
	virtual ~GameOver();

	void init();
	static void menu(Juego * ptr);
};

