#include "BalaPlayer.h"

#include <iostream>

BalaPlayer::BalaPlayer(Juego* ptr, int px, int py, int vX, int vY) : Bala(ptr, px, py, vX, vY)
{
	textura = juego->getTextura(Juego::TBulletPlayer);

	tipo = PJ;
}


BalaPlayer::~BalaPlayer()
{
}

void BalaPlayer::update(int delta) {
	
	rect.x += velX * delta /3;
	rect.y += velY * delta /3;

	rectCollision.x = (rect.x + rect.w / 4) * delta;
	rectCollision.y = (rect.y + rect.h / 4) * delta;

	onCollision();
}

