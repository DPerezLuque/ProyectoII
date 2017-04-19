#include "Bala.h"



Bala::Bala(Juego* ptr, int px, int py, int vX, int vY) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TBulletPlayer);
	
	rect.w = 35;
	rect.h = 35;

	rect.x = px;
	rect.y = py;

	rectCollision.w = 32;
	rectCollision.h = 32;
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

	rect.x += velX * delta / 3;
	rect.y += velY * delta / 3;

	rectCollision.x = (rect.x + rect.w / 4) * delta;
	rectCollision.y = (rect.y + rect.h / 4) * delta;

	
	if (juego->touchesWall(this)) {
		printf("Bala Destruida (WALL) \n");
		dead = true;
	}
}


void Bala::onCollision(int vida, collision tipo){

	if (juego->touchesWall(this)) {
		printf("Bala Destruida (pared) \n");
		dead = true;
	}
}

void Bala::onCollision(ObjetoJuego * colisionado){
	
		printf("Bala Destruida (OBJETO) \n");
		dead = true;
	
}