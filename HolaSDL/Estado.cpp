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
	for (size_t aux = 0; aux < juego->arrayObjetos.size(); ++aux) {
		delete juego->arrayObjetos[aux];
		juego->arrayObjetos[aux] = nullptr;
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
	/*SDL_Rect rect;
	rect.h = height;
	rect.w = width;
	rect.x = 0;
	rect.y = 0;

	textura = juego->getTextura(Juego::TFondo);
	textura->draw(pRenderer, rect);*/

	//Dibuja los objetos
	for (int aux = 0; aux < juego->arrayObjetos.size(); ++aux) {
		if (!juego->arrayObjetos[aux]->isDead())
			juego->arrayObjetos[aux]->draw();
		//Muestra la ventana
	}

	//Dibuja interfaz, por encima de los objetos	
	for (int i = 0; i < elemInterfaz.size(); i++) {
		elemInterfaz[i]->draw();
	}

	SDL_RenderPresent(pRenderer);
};

void Estado::update(int delta)
{
	for (int aux = 0; aux < juego->arrayObjetos.size(); ++aux) {
		if (!juego->arrayObjetos[aux]->isDead())
			juego->arrayObjetos[aux]->update(delta);
	}
		
	for (int i = 0; i < elemInterfaz.size(); i++) {
		dynamic_cast<Interfaz*>(elemInterfaz[i])->update(juego->camera, 8);
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

