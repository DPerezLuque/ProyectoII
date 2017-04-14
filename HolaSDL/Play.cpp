#include "Play.h"
#include "ObjetoJuego.h"
#include "GameOver.h"
#include "Player.h"
#include "BalaPlayer.h"
#include "BalaEnemigo.h"
#include "enemy.h"
#include "BossRino.h"
#include <iostream>

using namespace std;


Play::Play(Juego* ptr) : Estado(ptr)
{
	init();
}

Play::~Play() {}



void Play::init() 
{
	arrayObjetos.push_back(new Player(juego, juego->camera.w / 2, juego->camera.h / 2)); 
	arrayObjetos.push_back(new BossRino(juego, 0, 0));
	//arrayObjetos.push_back(new Bala(juego, 300, 300, 0, 0));

}

void Play::update(int delta) {
	
	//El update de cada objeto debe comprobar las colisiones con el entorno
	
	//COLISIONES CON OBJETOS
	//PERSONAJE
	for (int i = 1; i < arrayObjetos.size(); ++i){
		if (!arrayObjetos[0]->isDead() && juego->checkCollision(arrayObjetos[0], arrayObjetos[i])){
			arrayObjetos[0]->onCollision();
		}
	}
	//LIMPIEZA DE VECTOR DE OBJETOS
	for (int aux = 0; aux < arrayObjetos.size(); ++aux) {
		if (arrayObjetos[aux]->isDead())
			arrayObjetos.erase(arrayObjetos.begin() + aux);
	}

	//COLISIONES CON ENTORNO
	//***********
	//EN PLAYER.CPP

	//UPDATE
	for (int i = 0; i < arrayObjetos.size(); ++i) {
		if (!arrayObjetos[i]->isDead())
			arrayObjetos[i]->update(delta);
	}
}

void Play::onClick() {

	for (int i = 0; i < arrayObjetos.size(); ++i) {
		if (!arrayObjetos[i]->isDead())
			arrayObjetos[i]->onClick();
	}

}


void Play::newDisparo(ObjetoJuego * po, int posX, int posY) {

	//posiciones del ratón
	int mX, mY;
	juego->getMousePos(mX, mY);
	
	int distance = sqrt((mX - posX)*(mX - posX) + (mY - posY)*(mY - posY));

	int vX = 75 * (mX - posX) / distance;
	int vY = 75 * (mY - posY) / distance;

	//Disparo
	arrayObjetos.push_back(new BalaPlayer(juego, posX, posY, vX, vY));
}

void Play::posPlayer(int& x, int& y) {
	static_cast <Player*>(arrayObjetos[0])->getPos(x, y);
}

void Play::newDisparoEnemigo(int posEx, int posEy, int targetX, int targetY, int velDis) {
							//desde donde dispara //hacia donde dispara     //velocidad disparo


	int distance = sqrt((targetX - posEx)*(targetX - posEx) + (targetY - posEy)*(targetY - posEy));

	if (distance == 0) //He puesto esto para que no salga la excepción de que divide entre 0
		distance = 5;

	int vX = velDis * (targetX - posEx) / distance;
	int vY = velDis * (targetY - posEy) / distance;

	if (vX == 0 && vY == 0){ // Para que con lo de antes no se quede la bala flotando
		vX = vY = 10; // Si se hace lo de que al tocar al jugador haga daño y te empuje un poco igual no hace falta
	}

	//Disparo
	arrayObjetos.push_back(new BalaEnemigo(juego, posEx, posEy, vX, vY));
}