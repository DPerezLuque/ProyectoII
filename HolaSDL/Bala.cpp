#include "Bala.h"



Bala::Bala(Juego* ptr, int px, int py, int vX, int vY) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TBulletPlayer);
	
	rect.w = 35;
	rect.h = 35;

	rect.x = px;
	rect.y = py;

	rectCollision.w = rect.w /2;
	rectCollision.h = rect.h /2;

	rectCollision.x = rect.x + rect.w / 4;
	rectCollision.y = rect.y + rect.h / 4;

	velX = vX;
	velY = vY;

	tipo = WEAPON;
}


Bala::~Bala()
{
}

void Bala::update(int delta) {

	//onCollision();

	rect.x += velX * delta / 3;
	rect.y += velY * delta / 3;

	rectCollision.x = rect.x;//(rect.x + rect.w / 4) * delta;
	rectCollision.y = rect.y;//(rect.y + rect.h / 4) * delta;

	if (juego->touchesWall(this))
		onCollision();
}


void Bala::onCollision(){

		dead = true;

}
