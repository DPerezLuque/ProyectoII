#include "Play.h"
#include "ObjetoJuego.h"
#include "objetoDecorativo.h"
#include "GameOver.h"
#include "Player.h"
#include "BalaPlayer.h"
#include "BalaEnemigo.h"
#include "enemy.h"
#include "BossRino.h"
#include "EnemigoPlanta.h"
#include <iostream>

#include "BarraVida.h"
#include "BarraVidaVacia.h"
#include "Cargador.h"
#include "Checkpoint.h"
#include "EnemigoPlanta.h"
#include "Dialogo.h"
#include "Aura.h"
#include "Botiquin.h"

using namespace std;

Play::Play(Juego* ptr) : Estado(ptr)
{
	init();
}

Play::~Play()
{
}

void Play::init() {
	juego->arrayObjetos.push_back(new Player(juego, 200, 300));
	juego->arrayObjetos.push_back(new Checkpoint(juego, 1100, 5650));	

	juego->arrayObjetos.push_back(new enemy(juego, 750, 550));	
	//juego->arrayObjetos.push_back(new enemy(juego, 650, 1150));
	//juego->arrayObjetos.push_back(new enemy(juego, 50, 50));

	//ENEMIGOS PLANTA
	juego->arrayObjetos.push_back(new EnemigoPlanta(juego, 1350, 1150));
	juego->arrayObjetos.push_back(new EnemigoPlanta(juego, 580, 1150));
	//juego->arrayObjetos.push_back(new EnemigoPlanta(juego, 320, 1800));
	//juego->arrayObjetos.push_back(new EnemigoPlanta(juego, 1220, 2800));
	//juego->arrayObjetos.push_back(new EnemigoPlanta(juego, 350, 3500));
	//juego->arrayObjetos.push_back(new EnemigoPlanta(juego, 130, 4550));
	//juego->arrayObjetos.push_back(new EnemigoPlanta(juego, 600, 5250));

	juego->stats.push_back(vidaAux);
	juego->stats.push_back(static_cast<Player*>(juego->arrayObjetos[0])->getVida()); // En player
	juego->stats.push_back(static_cast<Player*>(juego->arrayObjetos[0])->getBalas());

	elemInterfaz.push_back(new BarraVidaVacia(juego, juego->camera, 128, 32, 0, 0));
	elemInterfaz.push_back(new BarraVida(juego, juego->camera, 32, 32, 0, 0));
	elemInterfaz.push_back(new Cargador(juego, juego->camera, 75, 75, juego->SCREEN_WIDTH - 75, juego->SCREEN_HEIGHT - 85));
	
	///// OBJETOS DECORATIVOS  /////
	//juego->arrayObjetos.push_back(new objetoDecorativo(juego, 200, 400, "papelera1"));
	//juego->arrayObjetos.push_back(new objetoDecorativo(juego, 300, 200, "papelera2"));
	//juego->arrayObjetos.push_back(new objetoDecorativo(juego, 400, 200, "papelera3"));

	//juego->arrayObjetos.push_back(new objetoDecorativo(juego, 200, 400, "mesaEE"));
	//juego->arrayObjetos.push_back(new objetoDecorativo(juego, 504, 80, "MesaRota2"));
	//juego->arrayObjetos.push_back(new objetoDecorativo(juego, 600, 80, "MesaRota"));
	//juego->arrayObjetos.push_back(new objetoDecorativo(juego, 696, 80, "MesaPeque"));
	//juego->arrayObjetos.push_back(new objetoDecorativo(juego, 792, 80, "MesaCorazon"));
	juego->arrayObjetos.push_back(new objetoDecorativo(juego, -50, -200, "Humo"));


	//FUENTE DE BALAS
	fuenteCargador = new Texto(juego->getTexto(0), 28);
	mensaje = new Textura();
	Black = { 0, 0, 0, 255 }; //RGBA	
	Red = { 175, 20, 20, 255 }; //RGBA	
	mensaje->loadFromText(pRenderer, to_string(juego->stats[2]), *fuenteCargador, Black);
}

void Play::update(int delta) {

	//COLISIONES CON OBJETOS

	//PERSONAJE CON ENEMIGOS
	for (int i = 1; i < juego->arrayObjetos.size(); ++i){
		if (!juego->arrayObjetos[0]->isDead() && juego->checkCollision(juego->arrayObjetos[0], juego->arrayObjetos[i])){
			juego->arrayObjetos[0]->onCollision(juego->arrayObjetos[i]-> getType());
			juego->arrayObjetos[i]->onCollision(juego->arrayObjetos[0]->getType());
		}
	}

	//PERSONAJE CON BALAS ENEMIGAS
	for (int i = 0; i < juego->arrayEnemigas.size(); ++i) {
		if (!juego->arrayObjetos[0]->isDead() && juego->checkCollision(juego->arrayObjetos[0], juego->arrayEnemigas[i])) {
			juego->arrayObjetos[0]->onCollision(juego->arrayEnemigas[i]->getType());
			juego->arrayEnemigas[i]->onCollision(juego->arrayObjetos[0]->getType());
		}
	}

	//BALAS CON ENEMIGOS
	for (int i = 0; i < juego->arrayBalas.size(); ++i) {
		for (int j = 1; j < juego->arrayObjetos.size(); ++j) {
			if (!juego->arrayBalas[i]->isDead() && juego->checkCollision(juego->arrayBalas[i], juego->arrayObjetos[j])) {
				juego->arrayBalas[i]->onCollision(juego->arrayObjetos[j]->getType());
				juego->arrayObjetos[j]->onCollision(juego->arrayBalas[i]->getType());
			}
		}
	}

	/*
	//ARREGLAR
	for (int j = 0; j < juego->arrayBalas.size(); ++j) {
	if (!juego->arrayBalas[j]->isDead()) {
	if (juego->touchesWall(juego->arrayBalas[j]))
	juego->arrayBalas[j]->onCollision();
	else {
	for (int j2 = 1; j2 < juego->arrayObjetos.size(); ++j2) {
	if (juego->checkCollision(juego->arrayBalas[j], juego->arrayObjetos[j2])) {
	juego->arrayBalas[j]->onCollision();
	juego->arrayObjetos[j2]->onCollision();
	}
	}
	}

	}
	}


	juego->arrayObjetos[0]->onCollision(juego->arrayObjetos[i]);
	}
	}

	for (int j = 1; j < juego->arrayObjetos.size(); ++j) {
	if (!juego->arrayObjetos[j]->isDead() && juego->arrayObjetos[j]->getType() == WEAPON) {
	juego->arrayObjetos[j]->onCollision();
	}
	}

	*/
	if (juego->arrayObjetos[0]->isDead()){
		for (int i = 0; i < juego->stats.size(); i++) {
			juego->stats[i] = 0;
		}
		juego->exit = true;
	}
	else{
		//LIMPIEZA DE VECTOR DE OBJETOS
		for (int aux = 0; aux < juego->arrayObjetos.size(); ++aux) {
			if (juego->arrayObjetos[aux]->isDead())
				juego->arrayObjetos.erase(juego->arrayObjetos.begin() + aux);
		}
		for (int aux2 = 0; aux2 < juego->arrayBalas.size(); ++aux2) {
			if (juego->arrayBalas[aux2]->isDead())
				juego->arrayBalas.erase(juego->arrayBalas.begin() + aux2);
		}
		for (int aux3 = 0; aux3 < juego->arrayEnemigas.size(); ++aux3) {
			if (juego->arrayEnemigas[aux3]->isDead())
				juego->arrayEnemigas.erase(juego->arrayEnemigas.begin() + aux3);
		}

		//UPDATE

		for (int i = 0; i < juego->arrayObjetos.size(); ++i) {
			//if (!juego->arrayObjetos[i]->isDead())
			juego->arrayObjetos[i]->update(delta);
		}
		for (int x = 0; x < juego->arrayBalas.size(); ++x) {
			//if (!juego->arrayBalas[x]->isDead())
			juego->arrayBalas[x]->update(delta);
		}
		for (int x = 0; x < juego->arrayEnemigas.size(); ++x) {
			//if (!juego->arrayEnemigas[x]->isDead())
			juego->arrayEnemigas[x]->update(delta);
		}


		//	if (!juego->arrayObjetos[0]->isDead()){  //Si player esta vivo
		//Actualiza valores de la vida, las balas (Interfaz)
		for (int i = 0; i < juego->stats.size(); i++) {
			getStats(i);
		}

		for (int i = 0; i < elemInterfaz.size(); i++){
			elemInterfaz[i]->update(juego->camera, juego->stats[i]); //Cada elemento del vector tiene su propio contador
		}
	}


}


//DE MOMENTO Play tiene su propio draw
void Play::draw()
{
	//Limpia el buffer
	//SDL_RenderClear(pRenderer);
	SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	//Dibuja los objetos
	for (int aux = 0; aux < juego->arrayObjetos.size(); ++aux) {
		juego->arrayObjetos[aux]->draw();
	}
	for (int aux2 = 0; aux2 < juego->arrayBalas.size(); ++aux2) {
		juego->arrayBalas[aux2]->draw();
	}
	for (int aux3 = 0; aux3 < juego->arrayEnemigas.size(); ++aux3) {
		juego->arrayEnemigas[aux3]->draw();
	}

	//Dibuja interfaz, por encima de los objetos
	if (!juego->arrayObjetos[0]->isDead()){
		for (int i = 0; i < elemInterfaz.size(); i++) {
			elemInterfaz[i]->draw();
		}
		//Pintado de texto (cargador)	
		if (juego->stats[2] > 0 && !juego->arrayObjetos[0]->isDead()){
			fuenteCargador->load(juego->getTexto(1), 18);
			mensaje->loadFromText(pRenderer, to_string(juego->stats[2]), *fuenteCargador, Black);
			if (juego->stats[2] < 10){
				mensaje->render(pRenderer, juego->SCREEN_WIDTH - 44, juego->SCREEN_HEIGHT - 50);
			}
			else{ mensaje->render(pRenderer, juego->SCREEN_WIDTH - 54, juego->SCREEN_HEIGHT - 50); }
		}
		else{
			fuenteCargador->load(juego->getTexto(1), 18);
			mensaje->loadFromText(pRenderer, "Recargando", *fuenteCargador, Red);
			mensaje->render(pRenderer, ((juego->SCREEN_WIDTH / 2) - 100), ((juego->SCREEN_HEIGHT / 2) - 100));
		}
	}
	SDL_RenderPresent(pRenderer);
}

void Play::getStats(int i){

	switch (i)
	{
	case 1: //Vida
		juego->stats[i] = static_cast<Player*>(juego->arrayObjetos[0])->getVida();
		break;
	case 2: //Balas
		juego->stats[i] = static_cast<Player*>(juego->arrayObjetos[0])->getBalas();
		break;
	default:
		break;
	}
}

void Play::onClick() {

	for (int i = 0; i < juego->arrayObjetos.size(); ++i) {
		if (!juego->arrayObjetos[i]->isDead())
			juego->arrayObjetos[i]->onClick();
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
	juego->arrayBalas.push_back(new BalaPlayer(juego, posX, posY, vX, vY));
}

void Play::posPlayer(int& x, int& y) {
	static_cast <Player*>(juego->arrayObjetos[0])->getPos(x, y);
}

void Play::newDisparoEnemigo(int posEx, int posEy, int targetX, int targetY, int velDis) {
	//desde donde dispara //hacia donde dispara     //velocidad disparo


	int distance = sqrt((targetX - posEx)*(targetX - posEx) + (targetY - posEy)*(targetY - posEy));

	if (distance == 0) //He puesto esto para que no salga la excepción de que divide entre 0
		distance = 5;

	int vX = velDis * (targetX - posEx) / distance;
	int vY = velDis * (targetY - posEy) / distance;

	if (vX == 0 && vY == 0){ // Para que con lo de antes no se quede la bala flotando
		vX = vY = 10; // Si se hace lo de que al tocar al jugador haga daño y te empuje un poco igual no hace falta
	}

	//float vX = velDis * (targetX - posEx) / distance + 0.01; //Arreglad esto para que no se haga 0
	//float vY = velDis * (targetY - posEy) / distance + 0.01;

	//Disparo
	juego->arrayEnemigas.push_back(new BalaEnemigo(juego, posEx, posEy, vX, vY));
}