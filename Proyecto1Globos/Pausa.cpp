#include "Pausa.h"


Pausa::Pausa(juegoPG* pGame)
{
	cout << "Entramos en Pausa\n"; 
	pJuego = pGame;
	vObjetos.resize(2);
	vObjetos[0] = new Boton(onClickMenu2, pJuego, 100, 200, TBMenu);
	vObjetos[1] = new Boton(onClickResume, pJuego, 100, 300, TBResume);
}


Pausa::~Pausa()
{
	freeObjects();
}