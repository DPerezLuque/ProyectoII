#include "Player.h"



Player::Player(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TPlayer);
	rect.w = 100;
	rect.h = 100;

	velX = 0;
	velY = 0;

}


Player::~Player()
{
}

void Player::update() {
	
	//Move the dot left or right
	rect.x += juego->getVelX();
	//Move the dot up or down
	rect.y += juego->getVelY();
} 

bool Player::onClick() {
	
	static_cast <Play*> (juego->topEstado())->newDisparo(this, rect.x, rect.y);
	return true;
}
