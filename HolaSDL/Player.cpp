#include "Player.h"



Player::Player(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TPlayer);
	rect.w = 64;
	rect.h = 64;

	rectAnim = { 0, 0, 64, 64 };

	rectCollision.w = 32; //Hay que retocar esto
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
		printf("Wall touched!\n");
		rect.x -= juego->getVelX() * delta;
		rect.y -= juego->getVelY() * delta;		
		
	}/*
		//Move the dot left or right
		rect.x += juego->getVelX();
		//Move the dot up or down
		rect.y += juego->getVelY();
	*/
		contador += delta;
		if (contador >= 6){
			proceso();
			contador = 0;				
		}
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
