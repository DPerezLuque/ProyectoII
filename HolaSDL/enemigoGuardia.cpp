#include "enemigoGuardia.h"


#include <random>

enemigoGuardia::enemigoGuardia(Juego* ptr, int px, int py) : enemigoBase(ptr, px, py)
{
	textura = juego->getTextura(Juego::TEnemy);
	vida = 3;
	animado = false;
}


enemigoGuardia::~enemigoGuardia()
{
}


void enemigoGuardia::update(int delta) 
{	
	SDL_Rect rectPlayer;
	rectPlayer = juego->player->getRect();
	
	rectVida.x = rect.x - 20;
	rectVida.y = rect.y - 20;
	rectVida.w = 32 * vida;


	follow(rectPlayer.x, rectPlayer.y, delta);
	//(contDis < freDis - 10) ){ //Algo tope chungo para que se pare al disparar << no hace falta
	contDis += delta;

	if (contDis >= freDis) {
		shoot(rectPlayer.x, rectPlayer.y);
		contDis = 0;
	}

	rectCollision.x = rect.x;//(rect.x + rect.w / 3) * delta;
	rectCollision.y = rect.y;//(rect.y + rect.h / 3) * delta;

	if (inmunidad) {
		if (contInm < 50) contInm++;
		else if (contInm == 50)
		{
			inmunidad = false;
			contInm = 0;
		}
	}

}







