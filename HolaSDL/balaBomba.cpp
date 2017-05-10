#include "balaBomba.h"


balaBomba::balaBomba(Juego* ptr, int px, int py, int vX, int vY) : Bala(ptr, px, py, vX, vY)
{
	textura = juego->getTextura(Juego::TBalaBomba);

	tipo = ENEMY_WEAPON;

	rectAnim = { 0, 0, 32, 32 };

	//NOS HEMOS QUEDADO POR AQUI: TENEMOS QUE HACER anim de la bala y que salga la explosión al detonar
}


balaBomba::~balaBomba()
{
}

void balaBomba::update(int delta){

	cont += delta;

	if (cont >= autodestr) {
		onCollision(tipo);
		cont = 0;
	}

	rect.x += velX * delta / 3;
	rect.y += velY * delta / 3;

	rectCollision.x = rect.x;//(rect.x + rect.w / 4) * delta;
	rectCollision.y = rect.y;//(rect.y + rect.h / 4) * delta;

	if (juego->touchesWall(getRect()))
		onCollision(tipo);
}
