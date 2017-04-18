#include "Objeto.h"


Objeto::Objeto(Juego* ptr, int px, int py)
{
	juego = ptr;
	pRenderer = juego->getRender();

	//Position
	rect.x = px;
	rect.y = py;
}


Objeto::~Objeto() {
	juego = nullptr;
	textura = nullptr;
	pRenderer = nullptr;
}

void Objeto::draw() const
{
	textura->draw(pRenderer, rect.x - juego->camera.x, rect.y - juego->camera.y, rect);
}


bool Objeto::dentro(int x, int y)const
{

	return  (x >= rect.x && x <= (rect.w + rect.x) && y >= rect.y && y <= (rect.h + rect.y));
}

bool Objeto::onClick()
{
	//printf("onclick objeto \n");
	int x, y;
	juego->getMousePos(x, y);
	if (dentro(x, y)) {
		return true;
	}
	return false;
}

SDL_Rect Objeto::getRect(){
	return rectCollision;
}

void Objeto::gestorVida(int vidaObjeto) 
{
	vidaObjeto--;
	cout << vidaObjeto;

	if (vidaObjeto <= 0)
		dead = true;
}

void Objeto::onCollision(int vidaObjeto, collision tipo){

	for (int i = 0; i < juego->topEstado()->getSizeArray(); i++) {
		//Comprueba si se ha colisionado con el objeto de la posición i del array de objetos
		if (juego->checkCollision(this, juego->topEstado()->getObjeto(i))) {
			if (juego->topEstado()->getObjeto(i)->getType() == WEAPON)
			{
				gestorVida(vidaObjeto);

			}
		}
	}
}