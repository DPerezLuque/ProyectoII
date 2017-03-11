#include "GameOver.h"
#include "MenuPrincipal.h"
#include "Boton.h"
#include <string>

GameOver::GameOver(Juego* ptr, int p) : Estado(ptr) {
	arrayObjetos.resize(1); 

	init();
}


GameOver::~GameOver() {}

void GameOver::init()
{
	arrayObjetos[0] = new Boton(juego, width / 2 - 80, 300, menu, Juego::TBMenu);
}

void GameOver::menu(Juego * juego)
{
	juego->changeState(new MenuPrincipal(juego));
}

//SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Puntos", msg.c_str(), NULL); (ESTO A LO MEJOR NOS ES UTIL EN EL FUTURO)






