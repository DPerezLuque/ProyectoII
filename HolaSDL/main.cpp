


#include "SDL.h"
#include "Juego.h"
#include "Error.h"

void showError(std::string e);

int main(int argc, char* args[]){
	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	try {
		Juego juego;
		juego.run();
	}
	catch (Error & e) { showError(e.mensaje());	}
	
	return 0;
}

void showError(std::string e) {
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", e.c_str(), NULL);
}