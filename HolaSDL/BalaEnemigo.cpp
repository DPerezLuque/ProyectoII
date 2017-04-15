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
}


BalaEnemigo::~BalaEnemigo()
{
}

void BalaEnemigo::update(int delta) {
	rect.x += velX * delta;
	rect.y += velY * delta;
}

void BalaEnemigo::update() {
	rect.x += velX;
	rect.y += velY;
}