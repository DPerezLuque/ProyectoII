#include "BossRino.h"


BossRino::BossRino(Juego* ptr, int px, int py) : enemy(ptr, px, py)
{
	textura = juego->getTextura(Juego::TBulletEnemy);

	vel = 3;
	contDis = 0;
	velDis = 20;
	vida = 4;

	rect.w = 50;
	rect.h = 50;

	bool saved = false;

	rectCollision.w = 100;
	rectCollision.h = 100;
	rectCollision.x = (rect.x - rect.w / 3);
	rectCollision.y = (rect.y - rect.h / 3);
	velX = 0;
	velY = 0;

	tipo = ENEMY;
}


BossRino::~BossRino()
{
}

void BossRino::update(int delta){

	rectCollision.x = (rect.x - rect.w / 3) * delta;
	rectCollision.y = (rect.y - rect.h / 3) * delta;

	int targetX, targetY;
	getPlayerPos(targetX, targetY);

	switch (estado) {
	case NORMAL:
		contStun = 0;
		++contDis;
		follow(targetX, targetY);
		if (contDis >= 100) estado = PARADO;
		break;
	case PARADO:
		contDis = 0;
		contParado++;
		if (contParado >= 50) {
			estado = CARGA;
		}
		break;
	case CARGA:
		contParado = 0;
		if (!saved) { 
			distance = sqrt((targetX - rect.x)*(targetX - rect.x) + (targetY - rect.y)*(targetY - rect.y));
			if (distance == 0) distance = 1;
			saveTargetX = (targetX - rect.x) / distance;
			saveTargetY = (targetY - rect.y) / distance;
			saved = true;
		}
		carga(saveTargetX, saveTargetY);

		rectCollision.x = (rect.x + rect.w / 3) * delta;
		rectCollision.y = (rect.y + rect.h / 3) * delta;
		if (juego->touchesWall(this)) {
			//printf("Wall touched!\n");
			saved = false;
			estado = ESTUNEADO;
		}
		break;
	case ESTUNEADO:
		contStun++;
		if(contStun >= 70) estado = NORMAL;
	}
}

void BossRino::carga(float x, float y) {

	rect.x += 15 * x * juego->delta;
	rect.y += 15 * y * juego->delta;
}

void BossRino::onCollision(collision c) {
	/*if (vida < 3) {
		std::cout << "para";
	}*/
	if(c == ENVIROMENT && estado == CARGA){
		saved = false;
		estado = ESTUNEADO;
		vida -= 1;
		std::cout << vida << "\n";
	}
}
