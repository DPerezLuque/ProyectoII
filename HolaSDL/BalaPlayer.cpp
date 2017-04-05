#include "BalaPlayer.h"

BalaPlayer::BalaPlayer(Juego* ptr, int px, int py, int vX, int vY) : Bala(ptr, px, py, vX, vY)
{
	textura = juego->getTextura(Juego::TBulletPlayer);
	
	rect.w = 25;
	rect.h = 25;

	rect.x = px;
	rect.y = py;

	velX = vX;
	velY = vY;
}


BalaPlayer::~BalaPlayer()
{
}

void BalaPlayer::update() {
	rect.x += velX;
	rect.y += velY;
}