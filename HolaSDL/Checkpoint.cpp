#include "Checkpoint.h"


Checkpoint::Checkpoint(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TCheck);
	tipo = CHECK;
	rect.w = 64;
	rect.h = 64;
	cogido = false;
	rectAnim = { 0, 0, 64, 64 };	
	contador = 0;
}


Checkpoint::~Checkpoint()
{
}

void Checkpoint::update(int delta) {

	contador += delta;
	if (contador > 3){
		animar();
		contador = 0;
	}	
	rectCollision.x = (rect.x + rect.w / 3) * delta; //Esto requiere que vaya en el update?
	rectCollision.y = (rect.y + rect.h / 3) * delta;
}

void Checkpoint::draw() const {
	textura->drawAnimacion(pRenderer, rect.x - juego->camera.x, rect.y - juego->camera.y, rect, rectAnim);
}

void Checkpoint::animar(){
	if (cogido){
		if (rectAnim.x >= 832){ //896
			rectAnim.y = 64;
			rectAnim.x = 0;
		}
		if (rectAnim.x >= 832 && rectAnim.y >= 64){ //Aqui aun no entra
			rectAnim.x = 832;
			rectAnim.y = 64;
			cogido = false;
		}
		else {
			rectAnim.x += 64;
		}
	}
}

void Checkpoint::onCollision(ObjetoJuego * colisionado){
	//cuando haya colision:
	cogido = true;	//demasiados bools
	//SetPosition(); // igual no hay que pasar el player
	animar();
	cout << "Checkpoint cogido\n";
}

void Checkpoint::setPosition(Player* p, int x, int y){
	p->posIniX = x;
	p->posIniY = y;
}
