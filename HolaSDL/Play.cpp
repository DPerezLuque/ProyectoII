#include "Play.h"
#include "ObjetoJuego.h"
#include "GameOver.h"
#include "Player.h"
#include "BalaPlayer.h"

using namespace std;


Play::Play(Juego* ptr) : Estado(ptr)
{
	//arrayObjetos.resize(1);
	init();

}

Play::~Play() {}



void Play::init() 
{
	arrayObjetos.push_back(new Player(juego, 200, 200)); 
	
}

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

	//posiciones del ratón
	int mX, mY;
	juego->getMousePos(mX, mY);

	int distance = sqrt((mX - posX)*(mX - posX) + (mY - posY)*(mY - posY));

	int vX = 75 * (mX - posX) / distance;
	int vY = 75 * (mY - posY) / distance;

	//Disparo
	arrayObjetos.push_back(new BalaPlayer(juego, posX, posY, vX, vY));
}