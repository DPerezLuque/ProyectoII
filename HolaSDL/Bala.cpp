#include "Bala.h"



Bala::Bala(Juego* ptr, int px, int py, int vX, int vY) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TBulletPlayer);
	
	rect.w = 50;
	rect.h = 50;

	rect.x = px;
	rect.y = py;

	velX = vX;
	velY = vY;

	tipo = WEAPON;
}


Bala::~Bala()
{
}

void Bala::onCollision(){

}