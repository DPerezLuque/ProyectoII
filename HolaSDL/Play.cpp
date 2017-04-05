#include "Play.h"
#include "ObjetoJuego.h"
#include "GameOver.h"
#include "Player.h"
#include "BalaPlayer.h"
#include "Pausa.h"

using namespace std;


Play::Play(Juego* ptr) : Estado(ptr)
{
	player = new Player(juego, 200, 200);
	//arrayObjetos.resize(1);
	init();

	

}

Play::~Play() {}



void Play::init() 
{
	arrayObjetos.push_back(player); 
	
}

void Play:: handleEvent(SDL_Event e){

	//Control del de los eventos de ratón 
	if (e.type == SDL_MOUSEBUTTONUP) {
		if (e.button.button == SDL_BUTTON_LEFT) {
			
			mouseX = e.button.x;
			mouseY = e.button.y;
			onClick();
		}
		else if (e.button.button == SDL_BUTTON_RIGHT){
			//Lee mentes, eso es
		}

	}
	//

	//Comparar los estados del personaje para ver qué cosas puede hacer
	else if (e.type == SDL_KEYDOWN) {

		if (e.key.keysym.sym == SDLK_ESCAPE) {
			juego -> pushState(new Pausa(juego));
		}

		else {
			player->movimientoDown(e);
		}


	}

	else if (e.type == SDL_KEYUP) {

			player->movimientoUp(e);

	}

}//play

void Play::update() {
	
	for (int i = 0; i < arrayObjetos.size(); ++i) {
		arrayObjetos[i]->update();
	}
}

void Play::onClick() {

	//int i = arrayObjetos.size() - 1;

	for (int i = 0; i < arrayObjetos.size(); ++i) {
		arrayObjetos[i]->onClick();
	}

}


void Play::newDisparo(ObjetoJuego * po, int posX, int posY) {

	int distance = sqrt((mouseX - posX)*(mouseX - posX) + (mouseY - posY)*(mouseY - posY));

	int vX = 75 * (mouseX - posX) / distance;
	int vY = 75 * (mouseY - posY) / distance;

	//Disparo
	arrayObjetos.push_back(new BalaPlayer(juego, posX, posY, vX, vY));
}