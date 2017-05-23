#include "MenuOpciones.h"
#include "Boton.h"


MenuOpciones::MenuOpciones(Juego * ptr) : Estado(ptr)
{
	type = MENU_OPCIONES;

	resetCamera();
	juego->arrayMenu.push_back(new Boton(juego, width / 2 - 150, 250, Juego::TBControlsA, Juego::TBControlsE, BOTON_CONTROLS));
	juego->arrayMenu.push_back(new Boton(juego, width / 2 - 150, 350, Juego::TBSangreA, Juego::TBSangreE, BOTON_SANGRE));
	juego->arrayMenu.push_back(new Boton(juego, width / 2 - 150, 450, Juego::TBFilterA, Juego::TBFilterE, BOTON_FILTER));
	juego->arrayMenu.push_back(new Boton(juego, width / 2 - 150, 550, Juego::TBMenuA, Juego::TBMenuE, BOTON_MENU));
}


MenuOpciones::~MenuOpciones()
{
}
