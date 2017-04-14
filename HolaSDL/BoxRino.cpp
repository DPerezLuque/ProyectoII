#include "BoxRino.h"



BoxRino::BoxRino(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TBox);

	rect.w = 100;
	rect.h = 100;

	rectCollision.w = rect.w * 1.5;
	rectCollision.h = rect.h * 1.5;
	rectCollision.x = rect.x - rect.w / 3;
	rectCollision.y = rect.y - rect.h / 3;

	tipo = ENVIROMENT;
}


BoxRino::~BoxRino()
{
}

void BoxRino::update(int delta) {}

void BoxRino::onCollision(collision c) {}
