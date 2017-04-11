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
	init();
}

Play::~Play() {}



void Play::init() 
{
	arrayObjetos.push_back(new Player(juego, 200, 200)); 
	arrayObjetos.push_back(new enemy(juego, 0, 0));

	vidaAux = 0; //Barra Vacia

	stats.push_back(vidaAux);
	stats.push_back(dynamic_cast<Player*>(arrayObjetos[0])->getVida());
	stats.push_back(dynamic_cast<Player*>(arrayObjetos[0])->getBalas());

	elemInterfaz.push_back(new BarraVidaVacia(juego, camera_, 128, 32));
	elemInterfaz.push_back(new BarraVida(juego, camera_, 32, 32)); 
	elemInterfaz.push_back(new Cargador(juego, camera_, 75, 75));

	textoDePrueba = juego->getTexto(Juego::Arial);
	cosaDePrueba = new Textura();
	Black = { 255, 0, 0, 255 }; //RGBA	
	cosaDePrueba->loadFromText(pRenderer, "HOLA", textoDePrueba, Black);
	rectanTexto = { 80, 300, 300, 300 };	
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
		//Muestra la ventana
	}

	//Dibuja interfaz, por encima de los objetos
	for (int i = 0; i < elemInterfaz.size(); i++) {
		elemInterfaz[i]->draw();
	}
	//Pintado de texto (pruebas)	
	cosaDePrueba->draw(pRenderer, rectanTexto);
	cosaDePrueba->loadFromText(pRenderer, "HOLA", textoDePrueba, Black);
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
	default:
		break;
	}
}

void Play::update() {

	//Actualiza valores de la vida, las balas (Interfaz)
	for (int i = 0; i < stats.size(); i++) {
		getStats(i);
	}

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