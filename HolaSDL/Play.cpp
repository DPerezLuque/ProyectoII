#include "Play.h"
#include "ObjetoJuego.h"
#include "GameOver.h"
#include "Player.h"
#include "BalaPlayer.h"
#include "BalaEnemigo.h"
#include "enemy.h"

#include "BarraVida.h"
#include "BarraVidaVacia.h"
#include "Cargador.h"
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

	vidaAux = 4;
	vida = dynamic_cast<Player*>(arrayObjetos[0])->getVida();
	balas = dynamic_cast<Player*>(arrayObjetos[0])->getBalas();

	stats.push_back(vidaAux);
	stats.push_back(vida);
	stats.push_back(balas);

	elemInterfaz.push_back(new BarraVidaVacia(juego, camera_, 32, 32));
	elemInterfaz.push_back(new BarraVida(juego, camera_, 32, 32)); 
	elemInterfaz.push_back(new Cargador(juego, camera_, 75, 75));
	
}

void Play::update() {
	
	for (int i = 0; i < arrayObjetos.size(); ++i) {
		arrayObjetos[i]->update();
	}
	for (int i = 0; i < elemInterfaz.size(); i++){
		elemInterfaz[i]->update(camera_, stats[i]); //Cada elemento del vector tiene su propio contador
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

	float vX = velDis * (targetX - posEx) / distance + 0.01; //Arreglad esto para que no se haga 0
	float vY = velDis * (targetY - posEy) / distance + 0.01;

	//Disparo
	arrayObjetos.push_back(new BalaEnemigo(juego, posEx, posEy, vX, vY));
}