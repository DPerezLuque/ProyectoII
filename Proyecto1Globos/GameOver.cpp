#include "GameOver.h"

GameOver::GameOver(juegoPG* pGame){
	//Crea los botones en el vector de objetos
	cout << "Entramos en GameOver\n";
	pJuego = pGame;
	puntos = pJuego->getPuntos();		//Lo recibe de juego
	vObjetos.resize(2);
	vObjetos[0] = new Boton(onClickScore, pJuego, 100, 200, TBScore);
	vObjetos[1] = new Boton(onClickMenu, pJuego, 100, 300, TBMenu);
}


GameOver::~GameOver()
{
	freeObjects();
}
