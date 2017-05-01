#include "enemy.h"
#include "Player.h"

#include <random>

typedef unsigned int uint;

enemy::enemy(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TEnemy);
	barraVida = juego->getTextura(Juego::TBarraVida);

	vel = 6;
	freDis = 100;
	velDis = 20;

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

	vida = 3;	

	inmunidad = false;
	contInm = 0;

}


enemy::~enemy()
{
}
void enemy::draw() const{
	textura->draw(pRenderer, rect.x - juego->camera.x, rect.y - juego->camera.y, rect);
	barraVida->draw(pRenderer, rectVida.x - juego->camera.x, rectVida.y - juego->camera.y, rectVida);
}

void enemy::update(int delta) 
{	
	rectVida.x = rect.x - 20;
	rectVida.y = rect.y - 20;
	rectVida.w = 32 * vida;

	SDL_Rect rectPlayer;
	rectPlayer = juego->getPuntPJ()->getRect();			//Puntero al jugador chavalesss
	//static_cast <Play*> (juego->topEstado())->posPlayer(x, y);

	//<<COMPROBAR LAS COLISIONES AQUí>>
	//if (puedeMoverse), ejecutamos esto.   En el "Else", pondremos que avance hacia atrás o algo.

	if (contDis < freDis - 10){ //Algo tope chungo para que se pare al disparar
		follow(rectPlayer.x, rectPlayer.y, delta);
	}
	//follow(x, y);

	//follow(rectPlayer.x, rectPlayer.y, delta);
	++contDis;
	if (contDis >= freDis){
		shoot(rectPlayer.x, rectPlayer.y);
		contDis = 0;
	}
	//rectCollision = rect;

	rectCollision.x = rect.x;//(rect.x + rect.w / 3) * delta;
	rectCollision.y = rect.y;//(rect.y + rect.h / 3) * delta;

	if (inmunidad) {
		if (contInm < 50) contInm++;
		else if (contInm == 50)
		{
			inmunidad = false;
			contInm = 0;
		}
	}

}

void enemy::follow(int x, int y, float delta){ // posicion del objeto que vas a seguir 
	
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
	rect.x += (vX / 4) * delta;
	rect.y += (vY / 4) * delta;
}

void enemy::shoot(int targetX, int targetY){

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
	juego->arrayEnemigas.push_back(new BalaEnemigo(juego, rect.x, rect.y, vX, vY));
}

void enemy::actualizaVectCols() {	//Vector enemigo contiene: Jugador, bajasPJ, entorno.


	//uint porque el .size() es un uint y puede haber perdidas de memoria
	for (uint i = 0; i < juego->arrayObjetos.size(); i++) {
		if (juego->arrayObjetos[i]->getType() == PJ || juego->arrayObjetos[i]->getType() == PJ_WEAPON 
			|| juego->arrayObjetos[i]->getType() == DECORATIVO) {

			vectColsPropiasObjeto.push_back(juego->arrayObjetos[i]); // 
		}
	}

}

void enemy::onCollision(collision colision) { //onCollision de gestor de vida
										   //Se usa para que el enemigo no atravise los objetos decorativos tambien, ni las paredes ni nada
	switch (colision){

		case PJ:
			//gestorVida();
			//No sé jaja
		break;

		case PJ_WEAPON:
			gestorVida();
		break;

		case DECORATIVO:
			puedeMoverse = false;
		break;




	}
}

void enemy::gestorVida()
{
	if (!inmunidad){
		vida--;
		cout << "Vida enemigo: " << vida << "\n";
		inmunidad = true;
	}

	if (vida <= 0){
		cout << "Enemy Dead! \n";
		dead = true;


		/* generate secret number between 1 and 10: */
		//int rnd = 1 - 100 * (rand() % 100);

		//if (rnd % 2 == 0)
		//juego->creaAlmas(rect.x, rect.y, "¡Por fin me muero!");
		juego->spawnObjetos('a', rect.x, rect.y, "");
		juego->spawnObjetos('b', rect.x, rect.y, "");
		
		//Tiras un random mágico, de un 10% o asi												" "
		//Si el random cuela --> juego -> meteAlma(posEnemigoX, posEnemigoY, Opcional: string frasePredeterminada);			mensaje random (:D)
		//									 \																				 /
		//									  Crea el aura en la posicion del enemigo - - - - - - - - - - - - - - - - - - - +
		//																			 \
		//																			   + mensajes prediseñados para X enemigo

	}
}

