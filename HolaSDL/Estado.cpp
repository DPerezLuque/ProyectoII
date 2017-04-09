#include "Estado.h"

Estado::Estado(Juego* ptr)
{
	juego = ptr;

	pRenderer = juego->getRender();
	height = juego->getHeight();
	width = juego->getWidth();
}


Estado::~Estado() 
{
	for (size_t aux = 0; aux < arrayObjetos.size(); ++aux) {
		delete arrayObjetos[aux];
		arrayObjetos[aux] = nullptr;
	}

	juego = nullptr;
	textura = nullptr;
	pRenderer = nullptr;
}

void Estado::draw() 
{
	//Limpia el buffer
	SDL_RenderClear(pRenderer);

	//Dibuja el fondo (tendremos que cambiarlo cuando empecemos con los fondos y los niveles)
	/*SDL_Rect rect;
	rect.h = height;
	rect.w = width;
	rect.x = 0;
	rect.y = 0;

	textura = juego->getTextura(Juego::TFondo);
	textura->draw(pRenderer, rect);*/

	//Dibuja los objetos
	for (int aux = 0; aux < arrayObjetos.size(); ++aux) {
		arrayObjetos[aux]->draw();
		//Muestra la ventana
	}

	SDL_RenderPresent(pRenderer);
};

void Estado::update(int delta)
{
	for (int aux = 0; aux < arrayObjetos.size(); ++aux) {
		arrayObjetos[aux]->update(delta);
	}
}


void Estado::onClick() //VAMOS A CAMBIARLO O ELIMINARLO 
{
	int aux = arrayObjetos.size() - 1;
	bool flag = false;
	while (aux >= 0 && !flag) {
		if (arrayObjetos[aux]->onClick()) {
			flag = true;
		}
		--aux;
	}
}

void Estado::handleEvent(SDL_Event e){

	if (e.type == SDL_MOUSEBUTTONUP) {
		if (e.button.button == SDL_BUTTON_LEFT) {

			mouseX = e.button.x;
			mouseY = e.button.y;
			onClick();
		}
	}
}

void Estado::getMousePos(int & mpx, int & mpy) const
{
	mpx = mouseX;
	mpy = mouseY;
}

