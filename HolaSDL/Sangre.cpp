#include "Sangre.h"
#include <time.h>


Sangre::Sangre(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	srand(time(NULL));
	int ale = rand() % 3; //random entre 0 y 2
	if (ale == 0){
		textura = juego->getTextura(Juego::TSangre1);
	}
	else if (ale == 1){
		textura = juego->getTextura(Juego::TSangre2);
	}
	else if (ale == 2){
		textura = juego->getTextura(Juego::TSangre3);
	}

	rect.w = 128;
	rect.h = 128;
	
}


Sangre::~Sangre()
{
}

void Sangre::draw() const {
	textura->draw(pRenderer, rect.x - juego->camera.x, rect.y - juego->camera.y, rect);
}

void Sangre::update(int delta){
	cont += delta;
	if (cont >= 300){
		dead = true;
	}
}
