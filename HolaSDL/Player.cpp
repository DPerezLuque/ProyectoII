#include "Player.h"
#include <iostream>


Player::Player(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TPlayer);
	rect.w = 64;
	rect.h = 64;

	rectAnim = {0, 0, 64, 64};

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

void Player::draw() const {
	textura->drawAnimacion(pRenderer, rect.x - juego->camera.x, rect.y - juego->camera.y, rect, rectAnim);
}

void Player::animar(animacion current){ //derecha, izquierda, arriba, abajo
	switch (current)
	{
		case Player::derecha:
			rectAnim.y = 192; //Altura de la animacion		
			break;
		case Player::izquierda:
			rectAnim.y = 128; 		
			break;
		case Player::arriba:
			rectAnim.y = 64; 
			break;
		case Player::abajo:
			rectAnim.y = 0; 
			break;
		case Player::dchaUp:
			rectAnim.y = 320; 
			break;
		case Player::dchaDown:
			rectAnim.y = 256; 
			break;
		case Player::izdaUp:
			rectAnim.y = 384; 	
			break;
		case Player::izdaDown:
			rectAnim.y = 448; 
			break;
		default:
			break;
	}
	
	animacionBasica();
}

void Player::animacionBasica(){ //Para el paso de frames
	if (rectAnim.x >= 192){
		rectAnim.x = 0;
	}
	else {
		rectAnim.x += 64;
	}	
}

int aux = 0;

void Player::update(int delta) {

	//rect.x = rect.x - juego->camera.x;
	//rect.y = rect.y - juego->camera.y;

	//COMPROBAR AQUÍ LA COLISIÓN DEL JUGADOR CON TODO > LLAMAR CON UN FOR A CADA OBJETO DEL ARRAY
	//juego->checkCollision()
	/*for (int i = 0; i < 10; ++i){
		juego->checkCollision(this->rect, juego->topEstado()->)
	}*/	

	rect.x += juego->getVelX() * delta / 1.5f;
	rect.y += juego->getVelY() * delta / 1.5f;
	
	rectCollision.x = (rect.x + rect.w / 3) * delta;
	rectCollision.y = (rect.y + rect.h / 3) * delta;

	if (juego->touchesWall(this)){
		//printf("Wall touched!\n");
		rect.x -= juego->getVelX() * delta;
		rect.y -= juego->getVelY() * delta;
	}

	setCamera(juego->camera);

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

	//Para la animación:

		contador += delta;
		if (contador >= 6){
			proceso();
			contador = 0;				
		}

		//rectAnim.x = rect.x;
		//rectAnim.y = rect.y;
} 
void Player::proceso(){
	//ANIMACION

	if (juego->getVelX() > 0 && juego->getVelY() == 0){
		animar(derecha);
	}
	if (juego->getVelX() < 0 && juego->getVelY() == 0){
		animar(izquierda);
	}
	if (juego->getVelY() < 0 && juego->getVelX() == 0){
		animar(arriba);
	}
	if (juego->getVelY()  > 0 && juego->getVelX() == 0){
		animar(abajo);
	}
	if (juego->getVelX()  > 0 && juego->getVelY() < 0){
		animar(dchaUp);
	}
	if (juego->getVelX() > 0 && juego->getVelY() > 0){
		animar(dchaDown);
	}
	if (juego->getVelX() < 0 && juego->getVelY()  < 0){
		animar(izdaUp);
	}
	if (juego->getVelX()  < 0 && juego->getVelY()  > 0){
		animar(izdaDown);
	}

	if (juego->getVelX() == 0 && juego->getVelY() == 0){
		contador = 0;
		rectAnim.x = 0;
	}
}

bool Player::onClick() {

	//posiciones del ratón
	int mX, mY, posX, posY;
	juego->getMousePos(mX, mY);

	posX = rect.x + rect.w / 2;
	posY = rect.y + rect.h / 2;

	int distance = sqrt((mX - posX)*(mX - posX) + (mY - posY)*(mY - posY));

	int vX = 75 * (mX - posX) / distance;
	int vY = 75 * (mY - posY) / distance;

	//Disparo
	juego->arrayBalas.push_back(new BalaPlayer(juego, posX, posY, vX, vY));

	//static_cast <Play*> (juego->topEstado())->newDisparo(this, rect.x + rect.w / 2, rect.y + rect.h / 2);
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
