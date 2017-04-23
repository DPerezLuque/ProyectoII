#include "BalaEnemigo.h"

BalaEnemigo::BalaEnemigo(Juego* ptr, int px, int py, int vX, int vY) : Bala(ptr, px, py, vX, vY)
{
	textura = juego->getTextura(Juego::TBulletEnemy);


	tipo = ENEMY_WEAPON;

	//tipo = ENEMY; //Al final es enemy o weapon?

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

void BalaEnemigo::onCollision() {

	dead = true;
	/*//BALAS
	for (int j = 1; j < juego->arrayObjetos.size(); ++j) {
		if (juego->arrayObjetos[j]->getType() == WEAPON) {
			if (juego->checkCollision(juego->arrayObjetos[j], juego->arrayObjetos[0])) {
				juego->arrayObjetos[j]->onCollision(juego->arrayObjetos[0]);
			}
		}
	}*/
}