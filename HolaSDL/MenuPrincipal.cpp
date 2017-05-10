#include "MenuPrincipal.h"
#include "Play.h"
#include "Boton.h"

MenuPrincipal::MenuPrincipal(Juego* ptr) : Estado(ptr)
{
	type = MENU_PRINCIPAL;
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

}

void MenuPrincipal::init()
{
	juego->camera = { 0, 0, juego->SCREEN_WIDTH, juego->SCREEN_HEIGHT };
	juego->arrayMenu.push_back(new Boton(juego, width / 2 - 150, 300, Juego::TBPlayA, Juego::TBPlayE, BOTON_PLAY));
	juego->arrayMenu.push_back(new Boton(juego, width / 2 - 150, 450, Juego::TBExitA, Juego::TBExitE, BOTON_EXIT));
}
/*
void MenuPrincipal::update() {
	
	if (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) salir();
		else if (e.type == SDL_MOUSEBUTTONUP) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				std::cout << "CLICK";
				mouse_x = e.button.x; //+ (camera.x + camera.w / 2) - SCREEN_WIDTH / 2;
				mouse_y = e.button.y; //+ (camera.y + camera.h / 2) - SCREEN_HEIGHT / 2;
				onClick();
			}
			// else if(...)    
		}
	}
}*/

void MenuPrincipal::onClick() {

	int aux = 0;
	bool flag = false;

	while (aux < juego->arrayMenu.size() && !flag) {
		if (juego->arrayMenu[aux]->dentro(mouse_x, mouse_y)) 
			flag = true;
		else ++aux;
	}

	if (flag) {
		switch (juego->arrayMenu[aux]->getType()) 
		{
		case BOTON_PLAY:
			play();
			break;
		case BOTON_EXIT:
			salir();
			break;
		default:
			break;
		}
	}

}

/*
void MenuPrincipal::salir(){
	juego->setSalir();
}
*/
void MenuPrincipal::play(){
	//juego->changeState(new Play(juego));
	juego->estado->changeCurrentState(NIVEL_1);
}
