#include "BalaEnemigo.h"

BalaEnemigo::BalaEnemigo(Juego* ptr, int px, int py, int vX, int vY) : Bala(ptr, px, py, vX, vY)
{
	textura = juego->getTextura(Juego::TBulletEnemy);

	rect.w = 50;
	rect.h = 50;

	rect.x = px;
	rect.y = py;

	velX = vX;
	velY = vY;

	tipo = ENEMY;
}


BalaEnemigo::~BalaEnemigo()
{
}

void BalaEnemigo::update(int delta) {
	rect.x += velX * delta;
	rect.y += velY * delta;

	//onCollision(1, tipo);
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