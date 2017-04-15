#include "Player.h"
//#include "GestorVida.h"



Player::Player(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TPlayer);
	rect.w = 100;
	rect.h = 100;

	rectCollision.w = 32;
	rectCollision.h = 32;
	rectCollision.x = rect.x + rect.w / 3;
	rectCollision.y = rect.y + rect.h / 3;
	velX = 0;
	velY = 0;

	tipo = PJ;

	vidaActual = VIDAMAX; //Inicialización de la vida a su máximo
	inmunidad = false;
	contadorInmunidad = 0;
}


Player::~Player()
{
}

void Player::update(int delta) {

	rect.x += juego->getVelX() * delta;
	rect.y += juego->getVelY() * delta;
	
	rectCollision.x = (rect.x + rect.w / 3) * delta;
	rectCollision.y = (rect.y + rect.h / 3) * delta;

	if (juego->touchesWall(this)){
		//printf("Wall touched!\n");
		rect.x -= juego->getVelX() * delta;
		rect.y -= juego->getVelY() * delta;
		
		
	}/*
		//Move the dot left or right
		rect.x += juego->getVelX();
		//Move the dot up or down
		rect.y += juego->getVelY();
	*/

	if (inmunidad) {
		if (contadorInmunidad < 100) contadorInmunidad++;
		else if (contadorInmunidad == 100)
		{
			inmunidad = false;
			contadorInmunidad = 0;
		}
	}

	//COMPROBAR AQUÍ LA COLISIÓN DEL JUGADOR CON TODO > LLAMAR CON UN FOR A CADA OBJETO DEL ARRAY
	for (int i = 0; i < juego->topEstado()->getSizeArray(); ++i){
		//Comprueba si se ha colisionado con el objeto de la posición i del array de objetos
		if (juego->checkCollision(this, juego->topEstado()->getObjeto(i))) {
			if (juego->topEstado()->getObjeto(i)->getType() == ENEMY || juego->topEstado()->getObjeto(i)->getType() == BOSS)
			{
				if (!inmunidad) {
					vidaActual--;
					cout << vidaActual;
					inmunidad = true;
				}
			}
		}
	}

	//-- - Gestión de la vida-- -
	if (vidaActual <= 0) //GestorVida::muerteYDestruccion();
		dead = true;
	
} 

bool Player::onClick() {
	

	static_cast <Play*> (juego->topEstado())->newDisparo(this, rect.x + rect.w / 2, rect.y + rect.h / 2);
	return true;
}

void Player::getPos(int& x, int& y) {
	x = rect.x;
	y = rect.y;
}

void Player::onCollision(){

	//printf("Auch!");
	//dead = true;

}
