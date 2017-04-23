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
	rect.x += vX / 4;
	rect.y += vY /4;
}

void enemy::shoot(int targetX, int targetY){

	//static_cast <Play*> (juego->topEstado())->newDisparoEnemigo(rect.x, rect.y, targetX, targetY, velDis);
	
	int distance = sqrt((targetX - rect.x)*(targetX - rect.x) + (targetY - rect.y)*(targetY - rect.y));

	if (distance == 0) //He puesto esto para que no salga la excepción de que divide entre 0
		distance = 5;

	int vX = velDis * (targetX - rect.x) / distance;
	int vY = velDis * (targetY - rect.y) / distance;

	if (vX == 0 && vY == 0) { // Para que con lo de antes no se quede la bala flotando
		vX = vY = 10; // Si se hace lo de que al tocar al jugador haga daño y te empuje un poco igual no hace falta
	}

	//Disparo
	juego->arrayEnemigas.push_back(new BalaEnemigo(juego, rect.x, rect.y, vX, vY));
}

void enemy::onCollision() {
	cout << "Enemy Dead! \n";
	dead = true;
}