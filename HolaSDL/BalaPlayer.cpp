#include "BalaPlayer.h"

#include <iostream>

BalaPlayer::BalaPlayer(Juego* ptr, int px, int py, int vX, int vY) : Bala(ptr, px, py, vX, vY)
{
	textura = juego->getTextura(Juego::TBulletPlayer);

	tipo = PJ_WEAPON;

}


BalaPlayer::~BalaPlayer()
{
}
/*
void BalaPlayer::update(int delta) {
	
	rect.x += velX * delta /3;
	rect.y += velY * delta /3;

	rectCollision.x = (rect.x + rect.w / 4) * delta;
	rectCollision.y = (rect.y + rect.h / 4) * delta;


	onCollision(1, tipo);

	onCollision(this);

}
*/
/*void BalaPlayer::onCollision(int vida, collision tipo)
{
	Bala::onCollision(vida, tipo);

	for (int i = 0; i < juego->topEstado()->getSizeArray(); ++i) {
		//Comprueba si se ha colisionado con el objeto de la posición i del array de objetos
		if (juego->checkCollision(this, juego->topEstado()->getObjeto(i))) {
			if (juego->topEstado()->getObjeto(i)->getType() == ENEMY)
			{
				dead = true;

			}
		}
	}
}*/


void BalaPlayer::onCollision() {
	
	/*if (juego->touchesWall(this)) {
		printf("Bala Destruida (WALL) \n");
		dead = true;
	}
	else {

		for (int i = 1; i < juego->arrayObjetos.size(); ++i) {
			if (juego->arrayObjetos[i]->getType() == ENEMY || juego->arrayObjetos[i]->getType() == BOSS) {
				if (juego->checkCollision(this, juego->arrayObjetos[i])) {
					cout << "Bala destruida! (ENEMY) \n";
					juego->arrayObjetos[i]->onCollision();
					dead = true;
				}
			}
		}

	}*/
	printf("Bala Destruida (WALL) \n");
	dead = true;
}

