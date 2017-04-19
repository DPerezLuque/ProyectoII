#include "MenuPrincipal.h"
#include "Play.h"
#include "Boton.h"

MenuPrincipal::MenuPrincipal(Juego* ptr) : Estado(ptr)
{
	juego->arrayMenu.resize(2); //dos objetos = dos botones

	init();
}


MenuPrincipal::~MenuPrincipal() {}

void MenuPrincipal::init()
{
//	arrayObjetos[0] = new Boton(juego, width/2 - 80, 300, salir, Juego::TBExit);
//	arrayObjetos[1] = new Boton(juego, width / 2 - 80, 200, play, Juego::TBPlay);
}

void MenuPrincipal::salir(Juego * juego){
	juego->setSalir();
}

void MenuPrincipal::play(Juego * juego){
	juego->changeState(new Play(juego));
}
