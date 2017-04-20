#include "enemy.h"
#include "Player.h"


enemy::enemy(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TEnemy);

	vel = 6;
	freDis = 100;
	velDis = 20;

	rect.x = px;
	rect.y = py;

	rect.w = 50;
	rect.h = 50;


	tipo = ENEMY;

	vidaEnemigo = VIDAMAXENEMY;		
}


enemy::~enemy()
{
}

void enemy::update(int delta) 
{	
	SDL_Rect rectPlayer;
	rectPlayer = juego->arrayObjetos[0]->getRect();
	//static_cast <Play*> (juego->topEstado())->posPlayer(x, y);

	if (contDis < freDis - 10){ //Algo tope chungo para que se pare al disparar
		follow(rectPlayer.x, rectPlayer.y);
	}
	//follow(x, y);

	follow(rectPlayer.x, rectPlayer.y);
	++contDis;
	if (contDis >= freDis){
		shoot(rectPlayer.x, rectPlayer.y);
		contDis = 0;
	}

	rectCollision = rect;
//	onCollision(vidaEnemigo, tipo);
}

void enemy::follow(int x, int y){ // posicion del objeto que vas a seguir 
	
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
	rect.x += vX /2;
	rect.y += vY /2;
}

void enemy::shoot(int targetX, int targetY){

	static_cast <Play*> (juego->topEstado())->newDisparoEnemigo(rect.x, rect.y, targetX, targetY, velDis);
}

void enemy::onCollision() {
	cout << "Enemy Dead! \n";
	dead = true;
}