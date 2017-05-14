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
#include "EnergiaDisponible.h"
#include "Checkpoint.h"
#include "EnemigoPlanta.h"
#include "Dialogo.h"
#include "Aura.h"
#include "Botiquin.h"
#include "Bobina.h"

using namespace std;

Play::Play(Juego* ptr) : Estado(ptr)
{
	type = NIVEL_1;

	init();
}

Play::~Play()
{

}

void Play::init() {

	juego->player = new Player(juego, 200, 300);

	juego->arrayObjetos.push_back(juego->player);
	//juego->arrayObjetos.push_back(new Player(juego, 200, 300));
	//juego->arrayObjetos.push_back(new Checkpoint(juego, 1100, 5650));	

	//ENEMIGOS
	//ObjetoJuego * newEnemy = new enemy(juego, 750, 300); //                              AQUI TUVE EL PROBLEMA CON EL COMMIT
	juego->arrayObjetos.push_back(new enemy(juego, 750, 300));	
	//juego->arrayObjetos.push_back(new EnemigoPlanta(juego, 750, 300));
	//juego->enemyArray.push_back(newEnemy);
	//juego->arrayObjetos.push_back(new enemy(juego, 650, 1150));
	//juego->arrayObjetos.push_back(new enemy(juego, 50, 50));

//	juego->arrayObjetos.push_back(juego->playerBullets);

	//ENEMIGOS PLANTA
	//juego->arrayObjetos.push_back(new EnemigoPlanta(juego, 1350, 1150));
	//juego->arrayObjetos.push_back(new EnemigoPlanta(juego, 580, 1150));
	//juego->arrayObjetos.push_back(new EnemigoPlanta(juego, 320, 1800));
	//juego->arrayObjetos.push_back(new EnemigoPlanta(juego, 1220, 2800));
	//juego->arrayObjetos.push_back(new EnemigoPlanta(juego, 350, 3500));
	//juego->arrayObjetos.push_back(new EnemigoPlanta(juego, 130, 4550));
	//juego->arrayObjetos.push_back(new EnemigoPlanta(juego, 600, 5250));

	juego->elemInterfaz.push_back(new BarraVidaVacia(juego, juego->player, 128, 32, 0, 0));
	juego->elemInterfaz.push_back(new BarraVida(juego, juego->player, 32, 32, 0, 0));
	juego->elemInterfaz.push_back(new Cargador(juego, juego->player, 75, 75, juego->SCREEN_WIDTH - 75, juego->SCREEN_HEIGHT - 85));
	juego->elemInterfaz.push_back(new EnergiaDisponible(juego, juego->player, 32, 32, 0, 0));
	
	///// OBJETOS DECORATIVOS  /////
	//juego->arrayObjetos.push_back(new objetoDecorativo(juego, 200, 400, "papelera1"));
	//juego->arrayObjetos.push_back(new objetoDecorativo(juego, 300, 200, "papelera2"));
	//juego->arrayObjetos.push_back(new objetoDecorativo(juego, 400, 200, "papelera3"));

	//juego->arrayObjetos.push_back(new objetoDecorativo(juego, 200, 400, "mesaEE"));

//	juego->arrayObjetos.push_back(new objetoDecorativo(juego, 504, 80, "MesaRota2"));
//	juego->arrayObjetos.push_back(new objetoDecorativo(juego, 600, 80, "MesaRota"));
//	juego->arrayObjetos.push_back(new objetoDecorativo(juego, 696, 80, "MesaPeque"));
//	juego->arrayObjetos.push_back(new objetoDecorativo(juego, 792, 80, "MesaCorazon"));
//	juego->arrayObjetos.push_back(new objetoDecorativo(juego, -50, -200, "Humo"));
	//juego->arrayObjetos.push_back(new Bobina(juego, 300, 300));

	/*
	//FUENTE DE BALAS
	fuenteCargador = new Texto(juego->getTexto(0), 28);
	mensaje = new Textura();
	Black = { 0, 0, 0, 255 }; //RGBA	
	Red = { 175, 20, 20, 255 }; //RGBA	
	mensaje->loadFromText(pRenderer, to_string(juego->stats[2]), *fuenteCargador, Black);
	*/
}

void Play::update(int delta) {

	//COLISIONES CON OBJETOS
	for (int i = 0; i < juego->arrayObjetos.size(); ++i) {
		for (int j = 0; j < juego->arrayObjetos.size(); ++j) {
			if (juego->checkCollision(juego->arrayObjetos[i], juego->arrayObjetos[j])) {
				juego->arrayObjetos[i]->onCollision(juego->arrayObjetos[j]->getType());
				juego->arrayObjetos[j]->onCollision(juego->arrayObjetos[i]->getType());
			}
		}
	}

	/*
	for (auto obj1 : juego->arrayObjetos) {
		for (auto obj2 : juego->arrayObjetos) {
			if (juego->checkCollision(obj1, obj2)) {
				obj1->onCollision(obj2->getType());
				obj2->onCollision(obj1->getType());
			}
		}
		
	}
	*/

/*
	//PERSONAJE CON ENEMIGOS
	for (int i = 1; i < juego->arrayObjetos.size(); ++i){
		if (!juego->player->isDead() && juego->checkCollision(juego->player, juego->arrayObjetos[i])){
			juego->player->onCollision(juego->arrayObjetos[i]-> getType());
			juego->arrayObjetos[i]->onCollision(juego->player->getType());
		}
	}

	
	for (auto i : juego->arrayObjetos) // access by value, the type of i is int
		std::cout << i << ' ';
	std::cout << '\n';
	

	//PERSONAJE CON BALAS ENEMIGAS
	for (int i = 0; i < juego->enemyBullets.size(); ++i) {
		if (!juego->player->isDead() && juego->checkCollision(juego->player, juego->enemyBullets[i])) {
			juego->player->onCollision(juego->enemyBullets[i]->getType());
			juego->enemyBullets[i]->onCollision(juego->player->getType());
		}
	}

	//BALAS CON ENEMIGOS
	for (int i = 0; i < juego->playerBullets.size(); ++i) {
		for (int j = 1; j < juego->arrayObjetos.size(); ++j) {
			if (!juego->playerBullets[i]->isDead() && juego->checkCollision(juego->playerBullets[i], juego->arrayObjetos[j])) {
				juego->playerBullets[i]->onCollision(juego->arrayObjetos[j]->getType());
				juego->arrayObjetos[j]->onCollision(juego->playerBullets[i]->getType());
			}
		}
	}
	

*/

	for (auto i : juego->arrayObjetos) {
		if (!i->isInside())
			juego->addToScreen(i);
	}

	if (juego->player->isDead()){		
		juego->estado->changeCurrentState(GAME_OVER);
	}
	else{
		//LIMPIEZA DE VECTOR DE OBJETOS
		for (int aux = 0; aux < juego->arrayObjetos.size(); ++aux) {
			if (juego->arrayObjetos[aux]->isDead())
				juego->arrayObjetos.erase(juego->arrayObjetos.begin() + aux);
		}
		for (int aux2 = 0; aux2 < juego->playerBullets.size(); ++aux2) {
			if (juego->playerBullets[aux2]->isDead())
				juego->playerBullets.erase(juego->playerBullets.begin() + aux2);
		}
		for (int aux3 = 0; aux3 < juego->enemyBullets.size(); ++aux3) {
			if (juego->enemyBullets[aux3]->isDead())
				juego->enemyBullets.erase(juego->enemyBullets.begin() + aux3);
		}
		for (int aux4 = 0; aux4 < juego->objVisible.size(); ++aux4) {
			if (!juego->isInScreen(juego->objVisible[aux4]->getRect())) {
				juego->objVisible.erase(juego->objVisible.begin() + aux4);
			}
		}
		
		//UPDATE
		for (int i = 0; i < juego->arrayObjetos.size(); ++i) {
			juego->arrayObjetos[i]->update(delta);
		}
		/*for (int x = 0; x < juego->playerBullets.size(); ++x) {
			juego->playerBullets[x]->update(delta);
		}
		for (int x = 0; x < juego->enemyBullets.size(); ++x) {
			juego->enemyBullets[x]->update(delta);
		}*/

		for (int i = 0; i < juego->elemInterfaz.size(); i++){
			juego->elemInterfaz[i]->update(); //
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	for (int aux2 = 0; aux2 < juego->playerBullets.size(); ++aux2) {
		juego->playerBullets[aux2]->draw();
	}
	for (int aux3 = 0; aux3 < juego->enemyBullets.size(); ++aux3) {
		juego->enemyBullets[aux3]->draw();
	}

	//Dibuja interfaz, por encima de los objetos
	for (int i = 0; i < juego->elemInterfaz.size(); i++) {
		juego->elemInterfaz[i]->draw();
	}
		/*
		//Pintado de texto (cargador)	
		if (juego->stats[2] > 0 && !juego->player->isDead()){
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
		*/
	
	SDL_RenderPresent(pRenderer);
}


void Play::newDisparo(ObjetoJuego * po, int posX, int posY) {

	//posiciones del ratón
	int mX, mY;
	juego->getMousePos(mX, mY);

	int distance = sqrt((mX - posX)*(mX - posX) + (mY - posY)*(mY - posY));

	int vX = 75 * (mX - posX) / distance;
	int vY = 75 * (mY - posY) / distance;

	//Disparo
	juego->playerBullets.push_back(new BalaPlayer(juego, posX, posY, vX, vY));
}

void Play::posPlayer(int& x, int& y) {
	static_cast <Player*>(juego->player)->getPos(x, y);
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
	juego->enemyBullets.push_back(new BalaEnemigo(juego, posEx, posEy, vX, vY));
}

/*
void Play::getStats(int i){

switch (i)
{
case 1: //Vida
//	juego->stats[i] = static_cast<Player*>(juego->player)->getVida();
break;
case 2: //Balas
//	juego->stats[i] = static_cast<Player*>(juego->player)->getBalas();
break;
case 3:
//		juego->stats[i] = static_cast<Player*>(juego->player)->getDash();
break;
default:
break;
}
}
*/