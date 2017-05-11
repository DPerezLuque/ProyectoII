#include "EnemigoBomba.h"


EnemigoBomba::EnemigoBomba(Juego* ptr, int px, int py) : enemigoBase(ptr, px, py)
{
	vida = 6;
	rectAnim = { 0, 0, 144, 121 };

	rect.x = px;
	rect.y = py;
	rect.w = 64;
	rect.h = 64;
	rectCollision = rect;

	textura = juego->getTextura(Juego::TEnemigoBomba);

	contadorFrames = 0;
	animado = true;

	radioDisable = 550;
	radioEnable = 400;
}


EnemigoBomba::~EnemigoBomba()
{
}


void EnemigoBomba::animacionBasica(){ //Para el paso de frames
	if (rectAnim.x >= 430){
		rectAnim.x = 0;
	}
	else {
		rectAnim.x += 144;
	}
}

void EnemigoBomba::update(int delta){
	if (isActive()) {
		rectCollision = rect;
		SDL_Rect rectPlayer;
		rectPlayer = juego->player->getRect();

		//Barra de vida
		rectVida.x = rect.x - 35;
		rectVida.y = rect.y - 20;
		rectVida.w = 32 * vida;

		follow(rectPlayer.x, rectPlayer.y, delta);

		contadorFrames += delta;
		if (contadorFrames >= 7) { //Paso de imagenes mas lento
			animacionBasica();
			contadorFrames = 0;
		}

		//int x, y;
		SDL_Rect aux_rect;
		aux_rect = juego->player->getRect();
		
		++contDis;
		if (contDis >= freDis) {
			shoot(aux_rect.x, aux_rect.y, 'b');
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
