#pragma once
#include "EstadoPG.h"
#include "PlayPG.h"

class MenuPG : public EstadoPG
{
public:
	/*
	consta de dos botones (�Play� y �Exit�).
	Para cada bot�n define una funci�n de tipo CallBack_t.
	*/
	MenuPG(juegoPG* pGame);
	~MenuPG();

private:
	//CALLBACKS que deberan ser llamados por el boton, colocar esto aqu� o en juegoPG?
	static void onClickPlay(juegoPG* pJuego){ pJuego->changeState(new PlayPG(pJuego)); }
	static void onClickExit(juegoPG* pJuego){ pJuego->setSalir(); }


};