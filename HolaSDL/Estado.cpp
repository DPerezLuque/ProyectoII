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
	/*//Objetos
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
	pRenderer = nullptr;*/
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
			juego->arrayMenu[aux]->draw();
		
	}

	SDL_RenderPresent(pRenderer);
};


void Estado::update(){

	bool clicked = false;
	while (!clicked){

		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				salir();
				clicked = true;
			}
			else if (e.type == SDL_MOUSEBUTTONUP) {
				if (e.button.button == SDL_BUTTON_LEFT) {
					std::cout << "CLICK";
					clicked = true;
					mouse_x = e.button.x; //+ (camera.x + camera.w / 2) - SCREEN_WIDTH / 2;
					mouse_y = e.button.y; //+ (camera.y + camera.h / 2) - SCREEN_HEIGHT / 2;
					onClick();
				}
				// else if(...)    
			}
		}
	}
}


void Estado::salir(){
	juego->setSalir();
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

