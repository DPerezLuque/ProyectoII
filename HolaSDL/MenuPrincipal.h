#pragma once
#include "Estado.h"

class MenuPrincipal : public Estado
{
public:

	MenuPrincipal(Juego* ptr);
	virtual ~MenuPrincipal();

	void init();
	//void update();
	//void onClick();
	void draw();

protected:
	//void salir();
	//void play();
private:
	Textura* logo;
	SDL_Rect tamano;

	vector <string> musicNames;
	Musica* cancion;
	vector <Musica*> musicFiles;
};

