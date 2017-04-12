#include "Player.h"



Player::Player(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TPlayer);
	rect.w = 64;
	rect.h = 64;

	rectAnim = { 0, 0, 32, 32 };


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

void Player::draw() const {
	textura->drawAnimacion(pRenderer, rect, rectAnim);
}
void Player::animar(animacion current){ //derecha, izquierda, arriba, abajo
	switch (current)
	{
		case Player::derecha:
			rectAnim.y = 96; //Altura de la animacion		
			break;
		case Player::izquierda:
			rectAnim.y = 64; 		
			break;
		case Player::arriba:
			rectAnim.y = 32; 
			break;
		case Player::abajo:
			rectAnim.y = 0; 
			break;
		case Player::dchaUp:
			rectAnim.y = 160; 
			break;
		case Player::dchaDown:
			rectAnim.y = 128; 
			break;
		case Player::izdaUp:
			rectAnim.y = 192; 	
			break;
		case Player::izdaDown:
			rectAnim.y = 224; 
			break;
		default:
			break;
	}
	
	animacionBasica();
}

void Player::animacionBasica(){ //Para el paso de frames
	if (rectAnim.x >= 96){
		rectAnim.x = 0;
	}
	else {
		rectAnim.x += 32;
	}
}

void Player::update(int delta) {
	//COMPROBAR AQUÍ LA COLISIÓN DEL JUGADOR CON TODO > LLAMAR CON UN FOR A CADA OBJETO DEL ARRAY
	//juego->checkCollision()
	/*for (int i = 0; i < 10; ++i){
		juego->checkCollision(this->rect, juego->topEstado()->)
	}*/

	rect.x += juego->getVelX() * delta;
	rect.y += juego->getVelY() * delta;
	
	rectCollision.x = (rect.x + rect.w / 3) * delta;
	rectCollision.y = (rect.y + rect.h / 3) * delta;

	if (juego->touchesWall(this)){
		printf("Wall touched!\n");
		rect.x -= juego->getVelX() * delta;
		rect.y -= juego->getVelY() * delta;		
		
	}/*
		//Move the dot left or right
		rect.x += juego->getVelX();
		//Move the dot up or down
		rect.y += juego->getVelY();
	*/
	//ANIMACION
	if (juego->getVelX() * delta > 0 && juego->getVelY() * delta == 0){
		animar(derecha);
	}
	if (juego->getVelX() * delta < 0 && juego->getVelY() * delta == 0){
		animar(izquierda);
	}
	if (juego->getVelY() * delta < 0 && juego->getVelX() * delta == 0){
		animar(arriba);
	}
	if (juego->getVelY() * delta > 0 && juego->getVelX() * delta == 0){
		animar(abajo);
	}
	if (juego->getVelX() * delta > 0 && juego->getVelY() * delta < 0){
		animar(dchaUp);
	}
	if (juego->getVelX() * delta > 0 && juego->getVelY() * delta > 0){
		animar(dchaDown);
	}
	if (juego->getVelX() * delta < 0 && juego->getVelY() * delta < 0){
		animar(izdaUp);
	}
	if (juego->getVelX() * delta < 0 && juego->getVelY() * delta > 0){
		animar(izdaDown);
	}
	
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

	printf("Auch!");
	dead = true;

}
