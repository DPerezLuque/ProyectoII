#include "GameOver.h"
#include "MenuPrincipal.h"
#include "Boton.h"
#include <string>

GameOver::GameOver(Juego* ptr) : Estado(ptr) {

	init();
}


GameOver::~GameOver() {

}


void GameOver::init()
{
	resetCamera();
	juego->arrayMenu.push_back(new Boton(juego, width / 2 - 150, 300, Juego::TBRetryA, Juego::TBRetryE, BOTON_PLAY));
	juego->arrayMenu.push_back(new Boton(juego, width / 2 - 150, 450, Juego::TBMenuA, Juego::TBMenuE, BOTON_MENU));
}


//SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Puntos", msg.c_str(), NULL); (ESTO A LO MEJOR NOS ES UTIL EN EL FUTURO)






