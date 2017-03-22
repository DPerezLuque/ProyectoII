#include "Play.h"
#include "ObjetoJuego.h"
#include "GameOver.h"
#include "Player.h"
#include "BalaPlayer.h"
#include "BalaEnemigo.h"
#include "enemy.h"
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
	arrayObjetos.push_back(new enemy(juego, 0, 0));
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

void Play::posPlayer(int& x, int& y) {
	static_cast <Player*>(arrayObjetos[0])->getPos(x, y);
}

void Play::newDisparoEnemigo(int posEx, int posEy, int targetX, int targetY, int velDis) {
							//desde donde dispara //hacia donde dispara     //velocidad disparo

	int distance = sqrt((targetX - posEx)*(targetX - posEx) + (targetY - posEy)*(targetY - posEy));

	int vX = velDis * (targetX - posEx) / distance;
	int vY = velDis * (targetY - posEy) / distance;

	//Disparo
	arrayObjetos.push_back(new BalaEnemigo(juego, posEx, posEy, vX, vY));
}