#include "Pausa.h"
#include "MenuPrincipal.h"
#include "Boton.h"

Pausa::Pausa(Juego* ptr) : Estado(ptr)
{
	juego->arrayMenu.resize(2); //dos objetos = dos botones
	init();
}


Pausa::~Pausa()
{
}

void Pausa::init() {
	//arrayObjetos[0] = new Boton(juego, width / 2 - 80, 200, resume, Juego::TBResume);
	//arrayObjetos[1] = new Boton(juego, width / 2 - 80, 300, menu, Juego::TBMenu);

}

void Pausa::resume(Juego * juego) {
	juego->popState();
}

void Pausa::menu(Juego * juego)
{	
	juego->popState();
	juego->changeState(new MenuPrincipal(juego));
}