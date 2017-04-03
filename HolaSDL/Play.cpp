#include "Play.h"
#include "ObjetoJuego.h"
#include "GameOver.h"
#include "Player.h"
#include "BalaPlayer.h"
#include <iostream>

using namespace std;


Play::Play(Juego* ptr) : Estado(ptr)
{
	init();
}

Play::~Play() {}



void Play::init() 
{
	arrayObjetos.push_back(new Player(juego, 200, 200)); 
	arrayObjetos.push_back(new Bala(juego, 300, 300, 0, 0));
}

void Play::update() {
	
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

	for (int j = 0; j < arrayObjetos.size(); ++j){
	}
	
	//COLISIONES CON ENTORNO
	//***********
	//EN PLAYER.CPP

	//UPDATE
	for (int i = 0; i < arrayObjetos.size(); ++i) {
		if (!arrayObjetos[i]->isDead())
			arrayObjetos[i]->update();
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