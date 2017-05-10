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

void enemigoGuardia::follow(int x, int y, float delta){ // posicion del objeto que vas a seguir 
	
	int distance = sqrt((x - rect.x)*(x - rect.x) + (y - rect.y)*(y - rect.y));


	if (distance > vel / 2) { //este numero es un margen de error que tendra que ir acorde con la velocidad del enemigo (vel)

	//if (distance > vel / 2) { //este numero es un margen de error que tendra que ir a corde con la velocidad del enemigo (vel)

		vX = vel * (x - rect.x) / distance;
		vY = vel * (y - rect.y) / distance;
	}
	else {
		vX = 0;
		vY = 0;
	}
	if (juego->touchesWall(getRect())) {
		rect.x -= (vX / 2) * delta;
		rect.y -= (vY / 2) * delta;
	}
	else {
		rect.x += (vX / 2) * delta / 1.5f;
		rect.y += (vY / 2) * delta / 1.5f;
	}

}





