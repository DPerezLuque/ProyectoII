#include "Player.h"



Player::Player(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TPlayer);
	rect.w = 100;
	rect.h = 100;

	velX = 0;
	velY = 0;

	tipo = PJ;
}


Player::~Player()
{
}

void Player::update() {
	//COMPROBAR AQUÍ LA COLISIÓN DEL JUGADOR CON TODO > LLAMAR CON UN FOR A CADA OBJETO DEL ARRAY
	//juego->checkCollision()
	/*for (int i = 0; i < 10; ++i){
		juego->checkCollision(this->rect, juego->topEstado()->)
	}*/
	//Move the dot left or right
	rect.x += juego->getVelX();
	//Move the dot up or down
	rect.y += juego->getVelY();
} 

bool Player::onClick() {
	
	//juego->topEstado()->newDisparo(this, rect.x, rect.y);
	//printf("onclick player \n");
	static_cast <Play*> (juego->topEstado())->newDisparo(this, rect.x, rect.y);
	return true;
}

void Player::onCollision(){

	printf("Auch!");
	dead = true;

}