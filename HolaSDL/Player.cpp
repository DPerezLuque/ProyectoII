#include "Player.h"



Player::Player(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TPlayer);
	rect.w = 100;
	rect.h = 100;

	velX = 0;
	velY = 0;
	vida = 4;
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
	
	static_cast <Play*> (juego->topEstado())->newDisparo(this, rect.x + rect.w / 2, rect.y + rect.h / 2);
	return true;
}

void Player::getPos(int& x, int& y) {
	x = rect.x;
	y = rect.y;
}
