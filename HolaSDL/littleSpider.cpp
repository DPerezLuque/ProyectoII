#include "littleSpider.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


littleSpider::littleSpider(Juego* ptr, int px, int py) : enemigoBase(ptr, px, py)
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

	contadorMovimiento = contadorQuieto= 0;
	actualizaMov = true;
	nuevaPosicion();
}


littleSpider::~littleSpider()
{
}

void littleSpider::update(int delta){
	
		rectCollision = rect;
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
			if (contadorQuieto >= 40){	//Para seleccionar un nuevo movimiento
				nuevaPosicion();
				//cout << pos.first <<',' <<pos.second << '\n';
				actualizaMov = false;
				contadorQuieto = 0; 
				//pero ya se ha hecho en el if de más abajo.
			}

			else contadorQuieto++;
		}

		else{
			//cout << rect.x << ' , ' << rect.y << '\n';
			if (contadorMovimiento >= 80){
				contadorMovimiento = 0;
				actualizaMov = true;
			}
			else {
				follow(pos.first, pos.second, delta);
				contadorMovimiento++;
			}
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

void littleSpider::animacionBasica(){ //Para el paso de frames
	if (rectAnim.x >= 60){
		rectAnim.x = 0;
	}
	else {
		rectAnim.x += 32;
	}
}

void littleSpider::nuevaPosicion(){
	srand(time(NULL));

	SDL_Rect rectPlayer;
	rectPlayer = juego->player->getRect();
	directionX = directionY = 0;


	while (directionX == 0 && directionY == 0){
		directionX = (rand() % 1 +2 )-1;		//Decide el signo del random, de ambos por separado
		directionY = (rand() % 1 + 2) - 1;
	}
	int velocidadX = rectPlayer.x;				//Rango: [1,10] para la velocidad
	int velocidadY = rectPlayer.y;				//Rango: [1,10] para la velocidad

	int nuevaX = velocidadX * directionX;

	

	int nuevaY = velocidadY * directionY;
	pair <int, int> nuevaPos = make_pair(nuevaX, nuevaY);

	pos = nuevaPos;
}