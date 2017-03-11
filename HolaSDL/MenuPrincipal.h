#pragma once
#include "Estado.h"

class MenuPrincipal : public Estado
{
public:
	MenuPrincipal(Juego* ptr);
	virtual ~MenuPrincipal();

	static void salir(Juego * ptr);
	static void play(Juego * ptr);
	void init();
};

