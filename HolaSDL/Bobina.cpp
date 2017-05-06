#include "Bobina.h"


Bobina::Bobina(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TBobina);
	//tipo = ???
	rect.w = 96;
	rect.h = 129;

	rectAnim = { 0, 0, 78, 105 };
	rectCollision = rect;
	contador = 0;
}


Bobina::~Bobina()
{
}

void Bobina::update(int delta) {
	contador += delta;
	if (contador > 3){
		animar();
		contador = 0;
	}

	if (juego->checkCollision(this, juego->player))
		onCollision();
}

void Bobina::draw() const {
	textura->drawAnimacion(pRenderer, rect.x - juego->camera.x, rect.y - juego->camera.y, rect, rectAnim);
}

void Bobina::animar(){
	if (rectAnim.x >= 312){
		rectAnim.x = 0;
	}
	else {
		rectAnim.x += 78;
	}
}

void Bobina::onCollision(){
}
