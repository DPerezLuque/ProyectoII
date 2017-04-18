#include "BalaPlayer.h"

#include <iostream>

BalaPlayer::BalaPlayer(Juego* ptr, int px, int py, int vX, int vY) : Bala(ptr, px, py, vX, vY)
{
	textura = juego->getTextura(Juego::TBulletPlayer);


	rect.w = 35;
	rect.h = 35;

	tipo = WEAPON;

}


BalaPlayer::~BalaPlayer()
{
}

void BalaPlayer::update(int delta) {
	
	rect.x += velX * delta /3;
	rect.y += velY * delta /3;

	rectCollision.x = (rect.x + rect.w / 4) * delta;
	rectCollision.y = (rect.y + rect.h / 4) * delta;

	onCollision(1, tipo);
}

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

