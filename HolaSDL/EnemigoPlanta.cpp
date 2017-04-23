#include "EnemigoPlanta.h"


EnemigoPlanta::EnemigoPlanta(Juego* ptr, int px, int py) : enemy(ptr, px, py)
{
	textura = juego->getTextura(Juego::TEnemyPlanta); //TODO: cambiar a la textura de la planta
	//vidaEnemigo = 5;  //REVISAD ESTO PLIS
	rectAnim = { 0, 0, 32, 32 };
	contador = 0; 
}

void EnemigoPlanta::animacionBasica(){ //Para el paso de frames
	if (rectAnim.x >= 128){
		rectAnim.x = 0;
	}
	else {
		rectAnim.x += 32;
	}
}

EnemigoPlanta::~EnemigoPlanta()
{
}

void EnemigoPlanta::draw() const {
	textura->drawAnimacion(pRenderer, rect.x - juego->camera.x, rect.y - juego->camera.y, rect, rectAnim);
}
void EnemigoPlanta::update(int delta){
	contador += delta;
	if (contador >= 4){ //Paso de imagenes mas lento
		animacionBasica();
		contador = 0;
	}

	int x, y;
	static_cast <Play*> (juego->topEstado())->posPlayer(x, y);
	++contDis;
	if (contDis >= freDis){
		shoot(x, y);
		contDis = 0;
	}

	//onCollision(vidaEnemigo, tipo); //REVISAD ESTO PLIS
}
