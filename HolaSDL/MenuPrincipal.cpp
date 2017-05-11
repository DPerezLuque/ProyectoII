#include "MenuPrincipal.h"
#include "Play.h"
#include "Boton.h"

MenuPrincipal::MenuPrincipal(Juego* ptr) : Estado(ptr)
{
	type = MENU_PRINCIPAL;
	init();
}


MenuPrincipal::~MenuPrincipal() {


	/*for (int aux = 0; aux < juego->arrayMenu.size(); ++aux) {
			juego->arrayMenu.erase(juego->arrayMenu.begin() + aux);
	}
	/*for (size_t aux = 0; aux < juego->arrayMenu.size(); ++aux) {
		delete juego->arrayMenu[aux];
		juego->arrayMenu[aux] = nullptr;
	}*/

}

void MenuPrincipal::init()
{
	resetCamera();
	juego->arrayMenu.push_back(new Boton(juego, width / 2 - 150, 300, Juego::TBPlayA, Juego::TBPlayE, BOTON_PLAY));
	juego->arrayMenu.push_back(new Boton(juego, width / 2 - 150, 450, Juego::TBExitA, Juego::TBExitE, BOTON_EXIT));
}


