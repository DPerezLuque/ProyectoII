#include "BalaPlayer.h"

BalaPlayer::BalaPlayer(Juego* ptr, int px, int py, int vX, int vY) : Bala(ptr, px, py, vX, vY)
{
	textura = juego->getTextura(Juego::TBulletPlayer);

	tipo = PJ;
}


BalaPlayer::~BalaPlayer()
{
}

void BalaPlayer::update(int delta) {
	rect.x += velX * delta;
	rect.y += velY * delta;
}

