#include "MenuFinalJuego.h"

#include "MenuPrincipal.h"
#include "Boton.h"
#include <string>



MenuFinalJuego::MenuFinalJuego(Juego* ptr) : Estado(ptr)
{
	resetCamera();
	//juego->arrayMenu.push_back(new Boton(juego, width / 2 - 150, 300, Juego::TBRetryA, Juego::TBRetryE, BOTON_PLAY));
	juego->arrayMenu.push_back(new Boton(juego, width / 2 - 150, 350, Juego::TBMenuA, Juego::TBMenuE, BOTON_MENU));
	logo = juego->getTextura(Juego::TLogo);
	tamano = { 400, 100, 390, 176 };
	logo->draw(pRenderer, 300, 70, tamano);
}

MenuFinalJuego::~MenuFinalJuego()
{
}

void MenuFinalJuego::draw()
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

	for (int aux = 0; aux < juego->arrayMenu.size(); ++aux) {
		juego->arrayMenu[aux]->draw();

	}

	SDL_RenderPresent(pRenderer);
}


//SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Puntos", msg.c_str(), NULL); (ESTO A LO MEJOR NOS ES UTIL EN EL FUTURO)






