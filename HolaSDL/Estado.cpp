#include "Estado.h"
#include "Interfaz.h"

Estado::Estado(Juego* ptr)
{
	juego = ptr;

	pRenderer = juego->getRender();
	height = juego->getHeight();
	width = juego->getWidth();
	//camera_ = juego->getCamera();
}


Estado::~Estado() 
{
	//Objetos
	for (size_t aux = 0; aux < juego->arrayMenu.size(); ++aux) {
		delete juego->arrayMenu[aux];
		juego->arrayMenu[aux] = nullptr;
	}
	//Interfaz
	for (int i = 0; i < elemInterfaz.size(); i++){
		delete elemInterfaz[i]; 
		elemInterfaz[i] = nullptr;
	}

	juego = nullptr;
	textura = nullptr;
	pRenderer = nullptr;
}

void Estado::draw()
{
	//Limpia el buffer
	//
	
	//SDL_RenderClear(pRenderer);
	SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	//Dibuja el fondo (tendremos que cambiarlo cuando empecemos con los fondos y los niveles)
	SDL_Rect rect;
	rect.h = height;
	rect.w = width;
	rect.x = 0;
	rect.y = 0;

	textura = juego->getTextura(Juego::TFondo);
	textura->draw(pRenderer, 0, 0, rect);

	//Dibuja los objetos
	for (int aux = 0; aux < juego->arrayMenu.size(); ++aux) {
		if (!juego->arrayMenu[aux]->isDead())
			juego->arrayMenu[aux]->draw();
		//Muestra la ventana
	}

	/*
	//Dibuja interfaz, por encima de los objetos //Solo hará falta en Play.cpp	
	for (int i = 0; i < elemInterfaz.size(); i++) {
		elemInterfaz[i]->draw();
	}
	*/
	SDL_RenderPresent(pRenderer);
};

void Estado::update(int delta)
{
	for (int aux = 0; aux < juego->arrayObjetos.size(); ++aux) {
		if (!juego->arrayObjetos[aux]->isDead())
			juego->arrayObjetos[aux]->update(delta);
	}	
}


void Estado::onClick() //VAMOS A CAMBIARLO O ELIMINARLO 
{	
	/*int aux = juego->arrayObjetos.size() - 1;
	bool flag = false;
	while (aux >= 0 && !flag) {
		if (juego->arrayObjetos[aux]->onClick()) {
			flag = true;
		}
		--aux;
	}*/
};

