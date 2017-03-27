#include "Player.h"
#include "MovimientoJugador.h"


Player::Player(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TPlayer);
	movJugador = new MovimientoJugador();
	rect.w = 100;
	rect.h = 100;

	velX = 0;
	velY = 0;

}


Player::~Player()
{
}

void Player::update() {

	evento = juego->getEvent();

	movJugador->setMovimientoJugador(evento);
	
	movJugador->getMovimientoJugador(velX, velY);
} 

bool Player::onClick() {
	
	static_cast <Play*> (juego->topEstado())->newDisparo(this, rect.x, rect.y);
	return true;
}

void Player::dash(){}
