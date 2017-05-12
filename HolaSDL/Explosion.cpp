#include "Explosion.h"


Explosion::Explosion(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	rect.x = px;
	rect.y = py;
	rect.w = 64;
	rect.h = 64;
	rectCollision = rect;
	
	textura = juego->getTextura(Juego::TExplosionBomba);

	tipo = EXPLOSION;

	rectAnim = { 0, 0, 42, 35 };

	contAutodestr = 0;
	autodestr = 150;

}


Explosion::~Explosion()
{
}

void Explosion::update(int delta){
	
	contadorFrames += delta;
	if (contadorFrames >= 8) { //Paso de imagenes mas lento
		animacionBasica();
		contadorFrames = 0;
	}

	cont += delta;

	if (contAutodestr >= autodestr) { //No se autodestruye con el tiempo :/
		onCollision(tipo);
		contAutodestr = 0;
	}
}

void Explosion::animacionBasica(){ //Para el paso de frames
	if (rectAnim.x >= 126){
		rectAnim.x = 0;
	}
	else {
		rectAnim.x += 42;
	}
}
