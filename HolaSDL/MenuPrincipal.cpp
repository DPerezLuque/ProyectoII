#include "MenuPrincipal.h"
#include "Play.h"
#include "Boton.h"

MenuPrincipal::MenuPrincipal(Juego* ptr) : Estado(ptr)
{
	//type = MENU_PRINCIPAL;
	tamano = {400, 100, 390, 176};
	logo = juego->getTextura(Juego::TLogo);
	init();
}


MenuPrincipal::~MenuPrincipal() {


	/*for (int aux = 0; aux < juego->arrayMenu.size(); ++aux) {
			juego->arrayMenu.erase(juego->arrayMenu.begin() + aux);
	}
	/*for (size_t aux = 0; aux < juego->arrayMenu.size(); ++aux) {
		delete juego->arrayMenu[aux];
		juego->arrayMenu[aux] = nullptr;
	}*/

	for (int i = 0; i < musicFiles.size(); i++) {
		delete musicFiles[i];
	}

}

void MenuPrincipal::init()
{
	resetCamera();
	juego->arrayMenu.push_back(new Boton(juego, width / 2 - 150, 250, Juego::TBPlayA, Juego::TBPlayE, BOTON_PLAY));
	juego->arrayMenu.push_back(new Boton(juego, width / 2 - 150, 350, Juego::TBOptionsA, Juego::TBOptionsE, BOTON_OPTIONS));
	juego->arrayMenu.push_back(new Boton(juego, width / 2 - 150, 450, Juego::TBExitA, Juego::TBExitE, BOTON_EXIT));

	musicNames.push_back("..\\bmps\\Home.mp3");
	

	for (int j = 0; j < musicNames.size(); j++) {
		cancion = new Musica();
		cancion->load(musicNames[j]);
		musicFiles.push_back(cancion);
	}

	musicFiles[0]->play();
	
}

void MenuPrincipal::draw()
{
	//Limpia el buffer
	SDL_RenderClear(pRenderer);

	SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	//Dibuja el fondo (tendremos que cambiarlo cuando empecemos con los fondos y los niveles)
	SDL_Rect rect;
	rect.h = height;
	rect.w = width;
	rect.x = 0;
	rect.y = 0;

	textura = juego->getTextura(Juego::TFondo);
	textura->draw(pRenderer, 0, 0, rect);
	logo->draw(pRenderer, 300, 70, tamano);
	//Dibuja los objetos
	/*for (auto aux : juego->arrayMenu) {
	aux->draw();
	}*/

	for (int aux = 0; aux < juego->arrayMenu.size(); ++aux) {
		juego->arrayMenu[aux]->draw();

	}
	SDL_RenderPresent(pRenderer);
};


