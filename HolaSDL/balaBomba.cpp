#include "balaBomba.h"
#include "ExplosionEnemigoB.h"


balaBomba::balaBomba(Juego* ptr, int px, int py, int vX, int vY) : Bala(ptr, px, py, vX, vY)
{
	textura = juego->getTextura(Juego::TBalaBomba);

	tipo = ENEMY_WEAPON;

	balaAnimada = true;

	rectAnim = { 0, 0, 42, 35 };


	//   COSAS QUE NOS FALTAN
	//-Falta que la explosión aparezca si toca al jugador y demás objetos
	//-Ajustar medidas (las puse al azar)
	//-Revisar que quita vida (cuanta?)
}


balaBomba::~balaBomba()
{
}

void balaBomba::update(int delta){


	contadorFrames += delta;
	if (contadorFrames >= 8) { //Paso de imagenes mas lento
		animacionBasica();
		contadorFrames = 0;
	}

	cont += delta;

	if (cont >= autodestr) {
		onCollision(tipo);
		explosionBala();
		cont = 0;
	}

	rect.x += velX * delta / 3;
	rect.y += velY * delta / 3;

	rectCollision.x = rect.x;//(rect.x + rect.w / 4) * delta;
	rectCollision.y = rect.y;//(rect.y + rect.h / 4) * delta;

	if (juego->touchesWall(getRect())){
		onCollision(tipo);
		explosionBala();
	}
}

void balaBomba::animacionBasica(){ //Para el paso de frames
	if (rectAnim.x >= 126){
		rectAnim.x = 0;
	}
	else {
		rectAnim.x += 42;
	}
}

//Método que genera una nueva explosión y la guarda en los vectores de juego
void balaBomba::explosionBala(){
	juego->spawnObjetos('e', rect.x, rect.y," ");			//'e' = explosion
}
