#include "BossRino.h"
#include <time.h>


BossRino::BossRino(Juego* ptr, int px, int py) : enemigoBase(ptr, px, py)
{
	textura = juego->getTextura(Juego::TRino);

	contDis = 0;
	velDis = 20;
	vida = 4;
	rect.w = 96;
	rect.h = 96;

	bool saved = false;

	velX = 0;
	velY = 0;

	tipo = BOSS;

	rectAnim = { 0, 0, 96, 96 };
	contadorFrames = 0;
	animado = true;
	est = animacion::ABAJO;
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

	int lastY = rect.y;			//Uso lastY y lastX para calcular en qué dirección
	int lastX = rect.x;			//se está moviendo para cambiar la animación

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
	//ANIMACIÓN
	int restaY = lastY - rect.y;
	int restaX = lastX - rect.x;

	if (abs(restaY) > abs(restaX)) {
		if (restaY < 0) {
			//se mueve para abajo
			est = animacion::ABAJO;
		}
		else {
			//se mueve para arriba
			est = animacion::ARRIBA;
		}
	}
	else if (abs(restaY) < abs(restaX)){
		if (restaX < 0) {
			//se mueve hacia la derecha
			est = animacion::DERECHA;
		}
		else {
			//se mueve hacia la izquierda
			est = animacion::IZQUIERDA;
		}
	}
	else {
		est = animacion::QUIETO;
	}

	contadorFrames += delta;
	if (contadorFrames >= 8) { //Paso de imagenes mas lento
		animar(est);
		contadorFrames = 0;
	}

	//////////
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

void BossRino::animacionBasica()
{
	if (rectAnim.x >= 288) {
		rectAnim.x = 0;
	}
	else {
		rectAnim.x += 96;
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

void BossRino::animar(animacion current)
{
	switch (current)
	{
	case animacion::IZQUIERDA:
		rectAnim.y = 288; //Altura de la animacion		
		break;
	case animacion::DERECHA:
		rectAnim.y = 192;
		break;
	case animacion::ARRIBA:
		rectAnim.y = 96;
		break;
	case animacion::ABAJO:
		rectAnim.y = 0;
		break;
	case animacion::QUIETO:
		break;
	default:
		break;
	}
	animacionBasica();
}
