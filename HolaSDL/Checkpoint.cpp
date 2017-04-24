#include "Checkpoint.h"


Checkpoint::Checkpoint(Juego* ptr, int px, int py, Player* p) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TCheck);
	tipo = CHECK;
	rect.w = 64;
	rect.h = 64;
	cogido = false;
	rectAnim = rect;
	rectAnim.x = 0;
	rectAnim.y = 0;
	rectCollision = rect;
	contador = 0;
	jugador = p;
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

	if (juego->checkCollision(this, juego->arrayObjetos[0]))
		onCollision();
	//rectCollision.x = (rect.x + rect.w / 2) * delta; //Esto requiere que vaya en el update?
	//rectCollision.y = (rect.y + rect.h / 2) * delta;
}

void Checkpoint::draw() const {
	textura->drawAnimacion(pRenderer, rect.x - juego->camera.x, rect.y - juego->camera.y, rect, rectAnim);
}

void Checkpoint::animar(){
	if (cogido){
		if (rectAnim.x >= 832 && rectAnim.y == 0){ //896
			rectAnim.y = 64;
			rectAnim.x = 0;
		}
		if (rectAnim.x >= 832 && rectAnim.y == 64){ //
			rectAnim.x = 832;
			rectAnim.y = 64;
		//	cout << "CHECKPOINT FALSE\n";
			cogido = false;
		}
		else {
			rectAnim.x += 64;
		}
	}
}

void Checkpoint::onCollision(){
	//cuando haya colision:
	if (!cogido){
		cogido = true;
		setPosition(rect.x, rect.y);
		cout << "Checkpoint cogido\n";
	}
	
}

void Checkpoint::setPosition(int x, int y){
	jugador->posIniX = x;
	jugador->posIniY = y;
}