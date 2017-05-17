#include "Spider.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Spider::Spider(Juego* ptr, int px, int py) : enemigoBase(ptr, px, py)
{
	vida = 4;
	rectAnim = { 0, 0, 30, 36};

	rect.x = px;
	rect.y = py;
	rect.w = 64;
	rect.h = 64;
	rectCollision = rect;

	textura = juego->getTextura(Juego::TSpider);

	contadorFrames = 0;
	animado = true;

	radioDisable = 550;
	radioEnable = 400;
}


Spider::~Spider()
{

}
void Spider::update(int delta)
{
	if (isActive()) {
		rectCollision = rect;
		SDL_Rect rectPlayer;
		rectPlayer = juego->player->getRect();

		//Barra de vida
		rectVida.x = rect.x - 35;
		rectVida.y = rect.y - 20;
		rectVida.w = 32 * vida;

		follow(rectPlayer.x, rectPlayer.y, delta);

		contadorFrames += delta;
		if (contadorFrames >= 10) { //Paso de imagenes mas lento
			animacionBasica();
			contadorFrames = 0;
		}

	

		++contDis;
		if (contDis >= freDis) {
			shoot(rectPlayer.x, rectPlayer.y, 'r');
			contDis = 0;
		}

		//rectCollision.x = (rect.x + rect.w / 3) * delta;
		//rectCollision.y = (rect.y + rect.h / 3) * delta;

		if (inmunidad) {
			if (contInm < 50) contInm++;
			else if (contInm == 50)
			{
				inmunidad = false;
				contInm = 0;
			}
		}
	}
}

void Spider::animacionBasica(){ //Para el paso de frames
	if (rectAnim.x >= 60){
		rectAnim.x = 0;
	}
	else {
		rectAnim.x += 32;
	}
}

//Controla la vida del enemigo y lo elimina si ha muerto.
void Spider::gestorVida(){
	//if (!inmunidad){
		vida--;
		cout << "Vida enemigo: " << vida << "\n";
		//inmunidad = true;
	//}

	if (vida <= 0){
		cout << "Enemy Dead! \n";
		dead = true;


		
		int rnd = 1 - 100 * (rand() % 100);

		if (rnd % 5 == 0) juego->spawnObjetos('b', rect.x, rect.y, "");  //Droppea botiquines con un 20%

		//juego->creaAlmas(rect.x, rect.y, "¡Por fin me muero!");
		juego->spawnObjetos('a', rect.x, rect.y, "");
		juego->spawnObjetos('b', rect.x, rect.y, "");
	
		//Aquí hacemos el drop de las Spiders pequeñas tambien, por eso se redefine
		for (int i = 0; i < 4; i++){
			srand(time(NULL));
			int nuevaPosX = (rand() % 1 + 2) - 1;
			int nuevaPosY = (rand() % 1 + 2) - 1;
			juego->spawnObjetos('x', rect.x+(50*nuevaPosX), rect.y +(80*nuevaPosY), "");
		}

			juego->spawnObjetos('e', rect.x, rect.y, "");	//Explosión to guapa 
	}
}