#pragma once
#include "Estado.h"

class GameOver : public Estado
{
public:
	GameOver(Juego* ptr);
	virtual ~GameOver();

	void init();
	void onClick();
	void menu();
};

