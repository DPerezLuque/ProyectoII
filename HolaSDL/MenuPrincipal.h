#pragma once
#include "Estado.h"

class MenuPrincipal : public Estado
{
public:

	MenuPrincipal(Juego* ptr);
	virtual ~MenuPrincipal();

	void init();
	//void update();
	//void onClick();

protected:
	//void salir();
	void play();

};

