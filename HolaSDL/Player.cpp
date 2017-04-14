#include "Player.h"



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
}

Player::~Player()
{
}

void Player::update(int delta) {
	//COMPROBAR AQUÍ LA COLISIÓN DEL JUGADOR CON TODO > LLAMAR CON UN FOR A CADA OBJETO DEL ARRAY
	//juego->checkCollision()
	/*for (int i = 0; i < 10; ++i){
		juego->checkCollision(this->rect, juego->topEstado()->)
	}*/

	//movimiento
	rect.x += juego->getVelX() * delta;
	rect.y += juego->getVelY() * delta;
	
	//actualiza el rectangulo de colisiones
	rectCollision.x = (rect.x + rect.w / 3) * delta;
	rectCollision.y = (rect.y + rect.h / 3) * delta;

	if (juego->touchesWall(this) || obj == ENVIROMENT){
		//printf("Wall touched!\n");
		rect.x -= juego->getVelX() * delta;
		rect.y -= juego->getVelY() * delta;	
		obj = PJ; //para que se pueda seguir moviendo 
	}
	
} 

bool Player::onClick() {
	

	static_cast <Play*> (juego->topEstado())->newDisparo(this, rect.x + rect.w / 2, rect.y + rect.h / 2);
	return true;
}

void Player::onCollision(collision c){
	obj = c;
	if (obj == ENEMY) {
		printf("Auch!");
		//dead = true;
	}
}

void Player::getPos(int& x, int& y) {
	x = rect.x;
	y = rect.y;
}

