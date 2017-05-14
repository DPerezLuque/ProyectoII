#include "ExplosionEnemigoB.h"


ExplosionEnemigoB::ExplosionEnemigoB(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	rect.x = px - 150;
	rect.y = py - 150;
	rect.w = 300;
	rect.h = 300;
	rectCollision = rect;
	
	textura = juego->getTextura(Juego::TExplosionBomba);

	tipo = EXPLOSION;

	rectAnim = { 0, 0, 205, 195};

	contAutodestr = 0;
	autodestr = 10;

	animado = true;
	
}


ExplosionEnemigoB::~ExplosionEnemigoB()
{
}

void ExplosionEnemigoB::update(int delta){
	
	contadorFrames += delta;
	if (contadorFrames >= 10) { //Paso de imagenes mas lento (en funcion del valor)
		animacionBasica();
		contadorFrames = 0;
	}

	cont += delta;

}

void ExplosionEnemigoB::animacionBasica(){ //Para el paso de frames
	if (rectAnim.x >= 2460){
		dead = true;
	}
	else {
		rectAnim.x += 205;
	}
}

void ExplosionEnemigoB::compruebaColisiones() {
	for (int i = 0; i < juego->arrayObjetos.size(); i++){
		juego->checkCollision(this, juego->arrayObjetos[i]);
	}
	
}