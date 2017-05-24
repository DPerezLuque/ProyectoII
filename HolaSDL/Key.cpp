#include "Key.h"


Key::Key(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TKey);
	tipo = KEY;
	rect.w = 64;
	rect.h = 64;

	rectCollision = rect;
}


Key::~Key()
{
}

void Key::onCollision(collision type){
	//Destroy();
}

void Key::update(int delta){
	Oscilar(delta);
}
