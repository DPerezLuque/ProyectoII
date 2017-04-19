#include "Player.h"
#include <iostream>

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
	vida = 2;
	balas = 30;
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

	//rect.x = rect.x - juego->camera.x;
	//rect.y = rect.y - juego->camera.y;

	rect.x += juego->getVelX() * delta;
	rect.y += juego->getVelY() * delta;
	
	rectCollision.x = (rect.x + rect.w / 3) * delta;
	rectCollision.y = (rect.y + rect.h / 3) * delta;

	if (juego->touchesWall(this)){

		//printf("Wall touched!\n");
		rect.x -= juego->getVelX() * delta;
		rect.y -= juego->getVelY() * delta;	
	}

	setCamera(juego->camera);
	
	//std::cout << "RECT X JUGADOR: " << rect.x << "\n";
	//std::cout << "CAMARA X: " << juego->camera.x << "\n";

} 

bool Player::onClick() {
	
	static_cast <Play*> (juego->topEstado())->newDisparo(this, rect.x + rect.w / 2, rect.y + rect.h / 2);
	return true;
}

void Player::getPos(int& x, int& y) {
	x = rect.x;
	y = rect.y;
}


void Player::onCollision(ObjetoJuego * colisionado){

	if (colisionado->getType() == CHECK){
		colisionado->onCollision(this);
	}
	else{
		printf("Auch!");
		dead = true;
	}
}

void Player::setCamera(SDL_Rect& camera)
{
	//Center the camera over the dot
	camera.x = (rect.x + rect.w / 2) - camera.w / 2;
	camera.y = (rect.y + rect.h / 2) - camera.h / 2;
	
	//Keep the camera in bounds
	if (camera.x < 0)
	{
		camera.x = 0;
	}
	if (camera.y < 0)
	{
		camera.y = 0;
	}
	if (camera.x > 2560 - camera.w)
	{
		camera.x = 2560 - camera.w;
	}
	if (camera.y > 7360 - camera.h)
	{
		camera.y = 7360 - camera.h;
	}
}
