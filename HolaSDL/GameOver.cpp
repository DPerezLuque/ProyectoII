#include "GameOver.h"
#include "MenuPrincipal.h"
#include "Boton.h"
#include <string>

GameOver::GameOver(Juego* ptr) : Estado(ptr) {

	init();
}


GameOver::~GameOver() {

}


void GameOver::init()
{
	juego->arrayMenu.push_back(new Boton(juego, width / 2 - 150, 300, Juego::TBPlayA, BOTON_MENU));
	juego->arrayMenu.push_back(new Boton(juego, width / 2 - 150, 450, Juego::TBExitA, BOTON_EXIT));
}
/*
void GameOver::update(){
	/*
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
}
*/

void GameOver::onClick() {

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
		case BOTON_MENU:
			menu();
			break;
		case BOTON_EXIT:
			salir();
			break;
		default:
			break;
		}
	}

}

void GameOver::menu()
{
	juego->estado->changeCurrentState(MENU_PRINCIPAL);

}

//SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Puntos", msg.c_str(), NULL); (ESTO A LO MEJOR NOS ES UTIL EN EL FUTURO)






