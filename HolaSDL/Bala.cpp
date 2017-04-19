#include "Bala.h"



Bala::Bala(Juego* ptr, int px, int py, int vX, int vY) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TBulletPlayer);
	
	rect.w = 50;
	rect.h = 50;

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


void Bala::onCollision(int vida, collision tipo){

	if (juego->touchesWall(this)) {
		//printf("Bala Destruida");
	}
}

void Bala::onCollision(ObjetoJuego * colisionado){
	
	if (juego->touchesWall(this)) {
		printf("Bala Destruida\n");
		dead = true;
	}
}