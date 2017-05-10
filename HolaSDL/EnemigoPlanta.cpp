#include "EnemigoPlanta.h"

EnemigoPlanta::EnemigoPlanta(Juego* ptr, int px, int py) : enemigoBase(ptr, px, py)
{
	textura = juego->getTextura(Juego::TEnemyPlanta); //TO DO: cambiar a la textura de la planta
	vida = 4;
	rectAnim = { 0, 0, 32, 32 };
	contadorFrames = 0;
	animado = true;

	radioDisable = 550;
	radioEnable = 400;
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

void EnemigoPlanta::update(int delta){
	if (isActive()) {
		//Barra de vida
		rectVida.x = rect.x - 35;
		rectVida.y = rect.y - 20;
		rectVida.w = 32 * vida;

		contadorFrames += delta;
		if (contadorFrames >= 4) { //Paso de imagenes mas lento
			animacionBasica();
			contadorFrames = 0;
		}

		//int x, y;
		SDL_Rect aux_rect;
		aux_rect = juego->player->getRect();
		//static_cast <Play*> (juego->topEstado())->posPlayer(x, y); << Hay que evitar los cast
		++contDis;
		if (contDis >= freDis) {
			shoot(aux_rect.x, aux_rect.y);
			contDis = 0;
		}

		//rectCollision.x = (rect.x + rect.w / 3) * delta;
		//rectCollision.y = (rect.y + rect.h / 3) * delta;

		if (inmunidad) {
			if (contInm < 50) contInm++;
			else if (contInm == 50)
			{
				inmunidad = false;
				contInm = 0;
			}
		}
	}
}

