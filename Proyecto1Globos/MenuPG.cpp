#include "MenuPG.h"

MenuPG::MenuPG(juegoPG* pGame)
{
	pJuego = pGame;
	cout << "Entramos en menuPG \n";
	vObjetos.resize(2);
	//cout << "El tamaño de vObjetos es: " << vObjetos.size() << "\n";
	vObjetos[0] = new Boton(onClickPlay, pJuego, 100, 200, TBPlay);
	vObjetos[1] = new Boton(onClickExit, pJuego, 100, 300, TBExit);
}


MenuPG::~MenuPG()
{
	freeObjects();
}
