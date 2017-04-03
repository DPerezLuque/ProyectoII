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
	//SDL_RenderClear(pRenderer);
	SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
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
		if (!arrayObjetos[aux]->isDead())
			arrayObjetos[aux]->draw();
		//Muestra la ventana
	}

	SDL_RenderPresent(pRenderer);
};

void Estado::update()
{
	for (int aux = 0; aux < arrayObjetos.size(); ++aux) {
		if (!arrayObjetos[aux]->isDead())
			arrayObjetos[aux]->update();
	}
}


void Estado::onClick() //VAMOS A CAMBIARLO O ELIMINARLO 
{	
	/*int aux = arrayObjetos.size() - 1;
	bool flag = false;
	while (aux >= 0 && !flag) {
		if (arrayObjetos[aux]->onClick()) {
			flag = true;
		}
		--aux;
	}*/
};

