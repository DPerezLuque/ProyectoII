#include "enemigoBase.h"
#include "BalaEnemigo.h"
#include "BalaRalentizadora.h"
#include "balaBomba.h"
#include <time.h>

enemigoBase::enemigoBase(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	barraVida = juego->getTextura(Juego::TBarraVida);

	sonido = juego->getEfecto(Juego::punch);
	sonidoMuerte = juego->getEfecto(Juego::death);

	vel = 6;
	freDis = 100;
	velDis = 20;
	contInm = 0;

	rect.x = px;
	rect.y = py;
	rect.w = 50;
	rect.h = 50;

	rectCollision.x = rect.x;
	rectCollision.y = rect.y;
	rectCollision.w = rect.w / 2;
	rectCollision.h = rect.h / 2;

	rectVida.x = px - 20;
	rectVida.y = py + 50;
	rectVida.w = 128;
	rectVida.h = 10;


	tipo = ENEMY;

	inmunidad = false;
	active = false;

	srand(0);
}

enemigoBase::~enemigoBase()
{
}


void enemigoBase::draw() const{

	Objeto::draw();				//Dibuja el objeto con animacion o no, según el bool animado de Objeto.h

	barraVida->draw(pRenderer, rectVida.x - juego->camera.x, rectVida.y - juego->camera.y, rectVida);
	
}

void enemigoBase::follow(int x, int y, float delta){ // posicion del objeto que vas a seguir 

	int distance = sqrt((x - rect.x)*(x - rect.x) + (y - rect.y)*(y - rect.y));


	if (distance > vel / 2) { //este numero es un margen de error que tendra que ir acorde con la velocidad del enemigo (vel)

		vX = vel * (x - rect.x) / distance;
		vY = vel * (y - rect.y) / distance;
	}
	else {
		vX = 0;
		vY = 0;
	}
	if (juego->touchesWall(getRect())) {
		rect.x -= (vX / 2) * delta;
		rect.y -= (vY / 2) * delta;
	}
	else {
		rect.x += (vX / 2) * delta / 1.5f;
		rect.y += (vY / 2) * delta / 1.5f;
	}

}

void enemigoBase::onCollision(collision type){
	if (type == PJ_WEAPON){
		gestorVida();
		sonido->play();
	}
}

void enemigoBase::shoot(int targetX, int targetY, char bulletType){

	//static_cast <Play*> (juego->topEstado())->newDisparoEnemigo(rect.x, rect.y, targetX, targetY, velDis);

	int distance = sqrt((targetX - rect.x)*(targetX - rect.x) + (targetY - rect.y)*(targetY - rect.y));

	if (distance == 0) //He puesto esto para que no salga la excepción de que divide entre 0
		distance = 5;

	int vX = velDis * (targetX - rect.x) / distance;
	int vY = velDis * (targetY - rect.y) / distance;

	if (vX == 0 && vY == 0) { // Para que con lo de antes no se quede la bala flotando
		vX = vY = 10; // Si se hace lo de que al tocar al jugador haga daño y te empuje un poco igual no hace falta
	}

	
	//Disparo
	ObjetoJuego* nuevaBala;						//Creamos una "bala vacia" que definiremos en función del tipo de disparo que prefiramos.
	switch (bulletType){
		case 'n':	
			nuevaBala = new BalaEnemigo(juego, rect.x, rect.y, vX, vY);				//Balas normales
		break;

		case 'b':
			nuevaBala = new balaBomba(juego, rect.x, rect.y, vX, vY);				//Balas explosivas
		break;

		case 'r':
			nuevaBala = new balaRalentizadora(juego, rect.x, rect.y, vX, vY);		//Balas ralentizadoras
			break;
	}
	//Incluimos la bala creada en el juego
	juego->arrayObjetos.push_back(nuevaBala);
	juego->enemyBullets.push_back(nuevaBala);
}

//Controla la vida del enemigo y lo elimina si ha muerto.
void enemigoBase::gestorVida(){
	if (!inmunidad){
		vida--;
		cout << "Vida enemigo: " << vida << "\n";
		inmunidad = true;
	}

	if (vida <= 0){
		cout << "Enemy Dead! \n";
		sonidoMuerte->play();
		dead = true;

		srand(time(NULL));

		/* generate secret number between 1 and 10: */
		int rnd = rand() % 101;

		if (rnd % 5 == 0) {
			juego->spawnObjetos('b', rect.x, rect.y, "");
		}	//Droppea botiquines con un 20%		
		
		//juego->spawnObjetos('e', rect.x, rect.y, "");
		//juego->spawnObjetos('b', rect.x, rect.y, "");

		if (juego->getSangre()){ //Sangre
			juego->spawnObjetos('s', rect.x, rect.y, "");
		}
		else {}

		if (spawnAura){
			juego->spawnObjetos('a', rect.x, rect.y, "");
		}

		if (dropLlave){
			juego->spawnObjetos('k', rect.x, rect.y, "");
		}
	}
}

bool enemigoBase::isActive(){
	//std::cout << active << "\n";
	int x, y;
	juego->player->getPos(x, y);
	int distance = sqrt((x + 50 - rect.x + rect.w / 2)*(x + 50 - rect.x + rect.w / 2)
		+ (y + 50 - rect.y + rect.h / 2)*(y + 50 - rect.y + rect.h / 2)); // distancia entre los centros y no las esquinas
	//std::cout << distance << "\n";
	if (distance <= radioEnable) active = true;
	if (distance >= radioDisable) active = false;
	return active;
}

//FOLLOW ANTIGUO, BORRAR SI ES IGUAL QUE EL QUE EXISTE
/*void enemigoBase::follow(int x, int y, float delta){ // posicion del objeto que vas a seguir 

	int distance = sqrt((x - rect.x)*(x - rect.x) + (y - rect.y)*(y - rect.y));


	if (distance > vel / 2) { //este numero es un margen de error que tendra que ir acorde con la velocidad del enemigo (vel)

		//if (distance > vel / 2) { //este numero es un margen de error que tendra que ir a corde con la velocidad del enemigo (vel)

		vX = vel * (x - rect.x) / distance;
		vY = vel * (y - rect.y) / distance;
	}
	else {
		vX = 0;
		vY = 0;
	}
	if (juego->touchesWall(getRect())) {
		rect.x -= (vX / 2) * delta;
		rect.y -= (vY / 2) * delta;
	}
	else {
		rect.x += (vX / 2) * delta / 1.5f;
		rect.y += (vY / 2) * delta / 1.5f;
	}

}*/