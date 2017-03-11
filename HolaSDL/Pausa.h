#pragma once
#include "Estado.h"

class Pausa : public Estado
{
public:
	Pausa(Juego* ptr);
	virtual ~Pausa();

	static void resume(Juego * juego);
	static void menu(Juego * juego);
	void init();

};

