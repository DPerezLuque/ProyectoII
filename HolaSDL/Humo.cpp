#include "Humo.h"

Humo::Humo(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::THumo);
	rect.w = 768;
	rect.h = 768;

	rectAnim = { 0, 0, 256, 256 };
}

Humo::~Humo()
{
}

void Humo::animacionBasica(){ //Para el paso de frames
	if (rectAnim.x >= 768){
		rectAnim.x = 0;
	}
	else {
		rectAnim.x += 256;
	}
}
void Humo::update(int delta){

	contador += delta;
	if (contador > 50){
		animacionBasica();
		contador = 0;
	}
}

void Humo::draw() const {
	textura->drawAnimacion(pRenderer, rect.x - juego->camera.x, rect.y - juego->camera.y, rect, rectAnim);
}

