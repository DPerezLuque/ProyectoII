#include "Checkpoint.h"


Checkpoint::Checkpoint(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TCheck);
	rect.w = 64;
	rect.h = 64;
	cogido = false;
	rectAnim = { 0, 0, 64, 64 };	
}


Checkpoint::~Checkpoint()
{
}

void Checkpoint::update(int delta) {
	animar();
}

void Checkpoint::draw() const {
	textura->drawAnimacion(pRenderer, rect.x - juego->camera.x, rect.y - juego->camera.y, rect, rectAnim);
}

void Checkpoint::animar(){
	if (cogido){
		if (rectAnim.x >= 832){ //896
			rectAnim.x = 0;
		}
		else {
			rectAnim.x += 64;
		}
	}
}

void Checkpoint::onCollision(){
	//cuando haya colision:
	cogido = true;	
}
