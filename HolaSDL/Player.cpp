#include "Player.h"
#include <iostream>


Player::Player(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TPlayer);
	rect.w = 64;
	rect.h = 64;

	rectCollision.w = 32;
	rectCollision.h = 32;
	rectCollision.x = rect.x + rect.w / 3;
	rectCollision.y = rect.y + rect.h / 3;
	velX = 0;
	velY = 0;

	tipo = PJ;

	vida = 4;
	balas = 30;

	inmunidad = false;
	contadorInmunidad = 0;

}


Player::~Player()
{
}

void Player::update(int delta) {

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

	/*
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

	onCollision(vida, tipo);

	
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

void Player::onCollision(int vidaActual, collision tipo){
	/*
	//COMPROBAR AQUÍ LA COLISIÓN DEL JUGADOR CON TODO > LLAMAR CON UN FOR A CADA OBJETO DEL ARRAY
	for (int i = 0; i < juego->topEstado()->getSizeArray(); ++i) {
		//Comprueba si se ha colisionado con el objeto de la posición i del array de objetos
		if (juego->checkCollision(this, juego->topEstado()->getObjeto(i))) {
			if (juego->topEstado()->getObjeto(i)->getType() == ENEMY || juego->topEstado()->getObjeto(i)->getType() == BOSS)
			{
				gestorVida(vidaActual);
				
			}
		}
	}/*/
}

void Player::gestorVida(int vida)
{
	if (!inmunidad) {
		vida--;
		cout << vida;
		inmunidad = true;
	}

	if (vida <= 0)
		dead = true;
}

void Player::onCollision(ObjetoJuego * colisionado){

		printf("Auch! \n");
		//dead = true;
	

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
