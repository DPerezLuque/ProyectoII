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
}