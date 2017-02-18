#pragma once
#include "EstadoPG.h"
#include "MenuPG.h"

class Pausa : public EstadoPG
{
public:
	Pausa(juegoPG* pGame);
	~Pausa();

private:
	//CALLBACKS que deberan ser llamados por el boton, colocar esto aquí o en juegoPG?
	static void onClickResume(juegoPG* pJuego){ pJuego->popState(); }
	static void onClickMenu2(juegoPG* pJuego){ pJuego->changeState(new MenuPG(pJuego)); }
};


