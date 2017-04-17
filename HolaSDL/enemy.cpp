#include "enemy.h"
#include "Player.h"


enemy::enemy(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TEnemy);

	vel = 6;
	freDis = 100;
	velDis = 20;

	rect.w = 50;
	rect.h = 50;

}


enemy::~enemy()
{
}

void enemy::update() 
{	
}

void enemy::follow(int x, int y){ // posicion del objeto que vas a seguir 
	
	int distance = sqrt((x - rect.x)*(x - rect.x) + (y - rect.y)*(y - rect.y));

	if (distance > vel / 2) { //este numero es un margen de error que tendra que ir acorde con la velocidad del enemigo (vel)
		vX = vel * (x - rect.x) / distance;
		vY = vel * (y - rect.y) / distance;
	}
	else {
		vX = 0;
		vY = 0;
	}
	rect.x += vX;
	rect.y += vY;
}

void enemy::shoot(int targetX, int targetY){
	static_cast <Play*> (juego->topEstado())->newDisparoEnemigo(rect.x, rect.y, targetX, targetY, velDis);
}

void enemy::isActive(int x, int y) {
	int distance = sqrt((x + 50 - rect.x + rect.w / 2)*(x + 50 - rect.x + rect.w / 2)
		+ (y + 50 - rect.y + rect.h / 2)*(y + 50 - rect.y + rect.h / 2)); // distancia entre los centros y no las esquinas
	std::cout << distance << "\n";
	if (distance <= radioEnable) active = true;
	if (distance >= radioDisable) active = false;
}

void enemy::getPlayerPos(int& x, int& y) {
	static_cast <Play*> (juego->topEstado())->posPlayer(x, y);
}

