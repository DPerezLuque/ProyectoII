#include "BalaEnemigo.h"

BalaEnemigo::BalaEnemigo(Juego* ptr, int px, int py, int vX, int vY) : Bala(ptr, px, py, vX, vY)
{
	textura = juego->getTextura(Juego::TBulletEnemy);
}


BalaEnemigo::~BalaEnemigo()
{
}



/*void BalaEnemigo::update() {
	rect.x += velX;
	rect.y += velY;
}*/

/*void BalaEnemigo:: onCollision (int vida, collision tipo)
{
	Bala::onCollision(vida, tipo);

	for (int i = 0; i < juego->topEstado()->getSizeArray(); ++i) {
		//Comprueba si se ha colisionado con el objeto de la posición i del array de objetos
		if (juego->checkCollision(this, juego->topEstado()->getObjeto(i))) {
			if (juego->topEstado()->getObjeto(i)->getType() == PJ || juego->topEstado()->getObjeto(i)->getType() == WEAPON)
			{
				dead = true;

			}
		}
	}
}*/