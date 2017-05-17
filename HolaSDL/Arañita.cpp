#include "Arañita.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


Arañita::Arañita(Juego* ptr, int px, int py) : enemigoBase(ptr, px, py)
{
	vida = 2;
	rectAnim = { 0, 0, 30, 36 };

	rect.x = px;
	rect.y = py;
	rect.w = 32;
	rect.h = 32;
	rectCollision = rect;

	textura = juego->getTextura(Juego::TSpider);

	contadorFrames = 0;
	animado = true;

	contadorMovimiento = 0;

}


Arañita::~Arañita()
{
}

void Arañita::update(int delta){
	

		//Barra de vida
		rectVida.x = rect.x - 35;
		rectVida.y = rect.y - 20;
		rectVida.w = 32 * vida;

		
		//Anímacion
		contadorFrames += delta;
		if (contadorFrames >= 10) { //Paso de imagenes mas lento
			animacionBasica();
			contadorFrames = 0;
		}

		//Movimiento
		if (actualizaMov){
			if (contadorMovimiento >= 80){	//Para seleccionar un nuevo movimiento
				pos = nuevaPosicion();
				actualizaMov = false;
				//contadorMovimiento = 0; pero ya se ha hecho en el if de más abajo.
			}

			else contadorMovimiento++;
		}


		if (rect.x == pos.first && rect.y == pos.second ){
			contadorMovimiento = 0;
			actualizaMov = true;
		}
		else follow(pos.first, pos.second, delta);

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

void Arañita::animacionBasica(){ //Para el paso de frames
	if (rectAnim.x >= 60){
		rectAnim.x = 0;
	}
	else {
		rectAnim.x += 32;
	}
}

pair  <int, int> Arañita::nuevaPosicion(){
	srand(time(NULL));

	int directionX = 1 - 2 * (rand() % 2);			//Decide el signo del random
	int velocidadX = rand() % 10 + 1;				//Rango: [1,10] para la velocidad

	int nuevaX = velocidadX * directionX;

	int directionY = 1 - 2 * (rand() % 2);			//Decide el signo del random
	int velocidadY = rand() % 10 + 1;				//Rango: [1,10] para la velocidad

	int nuevaY = velocidadY * directionY;
	pair <int, int> nuevaPos = make_pair(nuevaX, nuevaY);

	return pos;
}