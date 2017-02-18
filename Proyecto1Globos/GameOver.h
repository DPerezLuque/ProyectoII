#pragma once
#include "EstadoPG.h"
#include "MenuPG.h"

class GameOver : public EstadoPG
{
public:
	/*
	consta de uno o dos botones (“Score” y
	“Menu”). Para cada botón define una función de tipo CallBack_t.
	*/
	GameOver(juegoPG* pGame);
	~GameOver();
	virtual void update(){};
private:
	int puntos;

	//CALLBACKS que deberan ser llamados por el boton, colocar esto aquí o en juegoPG?
	static void onClickMenu(juegoPG* pJuego) { pJuego->changeState(new MenuPG(pJuego)); } //Cuerpo definido en Pausa
	static void onClickScore(juegoPG* pJuego){	pJuego->MostrarPuntuacion(); }
	/*
	static void onClickScore(juegoPG* pJuego){
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
			"Puntos", "Has conseguido: " + pJuego->getPuntos(), NULL);
	}
	*/
};