#include "Play.h"
#include "ObjetoJuego.h"
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
using namespace std;


Play::Play(Juego* ptr) : Estado(ptr)
{
	init();
}

Play::~Play() 
{
}

void Play::init() 
{
	arrayObjetos.push_back(new Player(juego, 200, 200)); 
	
	//arrayObjetos.push_back(new BossRino(juego, 0, 0));
	arrayObjetos.push_back(new Bala(juego, 300, 300, 0, 0));
	arrayObjetos.push_back(new Checkpoint(juego, 600, 250));
	//arrayObjetos.push_back(new enemy(juego, 0, 0));

	vidaAux = 0; //Barra Vacia

	stats.push_back(vidaAux);
	stats.push_back(dynamic_cast<Player*>(arrayObjetos[0])->getVida()); // En player
	stats.push_back(dynamic_cast<Player*>(arrayObjetos[0])->getBalas());

	elemInterfaz.push_back(new BarraVidaVacia(juego, juego->camera, 128, 32, 0, 0));
	elemInterfaz.push_back(new BarraVida(juego, juego->camera, 32, 32, 0, 0));
	elemInterfaz.push_back(new Cargador(juego, juego->camera, 75, 75, juego->camera.w - 80, juego->camera.h - 80));

	fuenteDePrueba = new Texto(juego->getTexto(0), 50);
	mensaje = new Textura();
	Red = { 255, 0, 0, 255 }; //RGBA	
	rectanTexto = { 80, 300, 300, 300 };
	mensaje->loadFromText(pRenderer, "Hola que tal", *fuenteDePrueba, Red);
}

void Play::update(int delta) {
	//El update de cada objeto debe comprobar las colisiones con el entorno
	
	//COLISIONES CON OBJETOS
	//PERSONAJE
	for (int i = 1; i < arrayObjetos.size(); ++i){
		if (!arrayObjetos[0]->isDead() && juego->checkCollision(arrayObjetos[0], arrayObjetos[i])){
			arrayObjetos[0]->onCollision(arrayObjetos[i]);
		}
	}
	//LIMPIEZA DE VECTOR DE OBJETOS
	for (int aux = 0; aux < arrayObjetos.size(); ++aux) {
		if (arrayObjetos[aux]->isDead())
			arrayObjetos.erase(arrayObjetos.begin() + aux);
	}

	//UPDATE
	for (int i = 0; i < arrayObjetos.size(); ++i) {
		if (!arrayObjetos[i]->isDead())
			arrayObjetos[i]->update(delta);
	}

	if (arrayObjetos[0]->isDead()){  //Si player esta vivo
		//Actualiza valores de la vida, las balas (Interfaz)
		for (int i = 0; i < stats.size(); i++) {
			getStats(i);
		}
	}

	for (int i = 0; i < elemInterfaz.size(); i++){
		elemInterfaz[i]->update(camera_, stats[i]); //Cada elemento del vector tiene su propio contador
	}
}


//DE MOMENTO Play tiene su propio draw
void Play::draw()
{
	//Limpia el buffer
	//SDL_RenderClear(pRenderer);
	SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	
	//Dibuja los objetos
	for (int aux = 0; aux < arrayObjetos.size(); ++aux) {
		arrayObjetos[aux]->draw();		
	}
	
	//Dibuja interfaz, por encima de los objetos
	for (int i = 0; i < elemInterfaz.size(); i++) {
		elemInterfaz[i]->draw();
	}

	//Pintado de texto (pruebas)	
	mensaje->render(pRenderer,300,300);

	SDL_RenderPresent(pRenderer);
}

void Play::getStats(int i){

	switch (i)
	{
	case 1: //Vida
		stats[i] = dynamic_cast<Player*>(arrayObjetos[0])->getVida();
		break;
	case 2: //Balas
		stats[i] = dynamic_cast<Player*>(arrayObjetos[0])->getBalas();
		break;
	default:
		break;
	}
}

void Play::onClick() {

	for (int i = 0; i < arrayObjetos.size(); ++i) {
		if (!arrayObjetos[i]->isDead())
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
	arrayObjetos.push_back(new BalaEnemigo(juego, posEx, posEy, vX, vY));
}