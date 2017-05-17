#include "BossRino.h"
#include <time.h>


BossRino::BossRino(Juego* ptr, int px, int py) : enemigoBase(ptr, px, py)
{
	textura = juego->getTextura(Juego::TEnemy);

	contDis = 0;
	velDis = 20;
	vida = 4;

	bool saved = false;

	velX = 0;
	velY = 0;

	tipo = BOSS;
}


BossRino::~BossRino()
{
}

void BossRino::update(int delta) {

	rectVida.x = rect.x - 20;
	rectVida.y = rect.y - 20;
	rectVida.w = 32 * vida;

	rectCollision.x = rect.x;
	rectCollision.y = rect.y;
	//std::cout << rectCollision.x << rectCollision.y  << "\n";

	int targetX, targetY;
	juego->player->getPos(targetX, targetY);

	switch (estado) {
	case NORMAL:
		contStun = 0;
		++contDis;
		follow(targetX, targetY, delta);
		if (contDis >= 100) estado = PARADO;
		break;
	case PARADO:
		contDis = 0;
		contParado++;
		if (contParado >= 80) {
			srand(time(NULL));
			atack = rand() % 2; 
			if (atack == 0) 
				estado = CARGA;
			else estado = SHOOT;
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

		rectCollision.x = rect.x;
		rectCollision.y = rect.y;
		if (juego->touchesWall(rectCollision)) {
			//printf("Wall touched!\n");
			saved = false;
			estado = ESTUNEADO;
		}
		break;
	case SHOOT:
		shoot(rect.x + 1, rect.y + 1, 'n');
		shoot(rect.x - 1, rect.y + 1, 'n');
		shoot(rect.x - 1, rect.y - 1, 'n');
		shoot(rect.x + 1, rect.y - 1, 'n');
		estado = ESTUNEADO;
		break;
	case ESTUNEADO:
		contStun++;
		if (contStun >= 70) estado = NORMAL;
	}
}

void BossRino::carga(float x, float y) {

	rect.x += 15 * x * juego->delta;
	rect.y += 15 * y * juego->delta;
}

void BossRino::onCollision(collision type) {
	if (type == PJ) {
		estado = ESTUNEADO;
		saved = false;
	}

	if (type == DECORATIVO && estado == CARGA) {
		saved = false;
		estado = ESTUNEADO;
		vida -= 1;
		std::cout << vida << "\n";
	}
}

void BossRino::follow(int x, int y, float delta) { // posicion del objeto que vas a seguir 

	int distance = sqrt((x - rect.x)*(x - rect.x) + (y - rect.y)*(y - rect.y));
	//std::cout << vel << "\n";

	if (distance > vel / 2) { //este numero es un margen de error que tendra que ir acorde con la velocidad del enemigo (vel)
		vX = vel * (x - rect.x) / distance;
		vY = vel * (y - rect.y) / distance;
	}
	else {
		vX = 0;
		vY = 0;
	}

	rect.x += (vX / 2) * delta / 1.5f;
	rect.y += (vY / 2) * delta / 1.5f;
}
