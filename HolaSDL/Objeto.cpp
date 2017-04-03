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
	textura->draw(pRenderer, rect);
}


bool Objeto::dentro(int x, int y)const
{

	return  (x >= rect.x && x <= (rect.w + rect.x) && y >= rect.y && y <= (rect.h + rect.y));
}

bool Objeto::onClick() //Devuelve true lo han pinchado, false si no lo han pinchado
{
	int x, y;
	juego->getMousePos(x, y);
	if (dentro(x, y)) {
		return true;
	}
	return false;
}


