#include "LittleSpider.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


LittleSpider::LittleSpider(Juego* ptr, int px, int py) : EnemigoBase(ptr, px, py)
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
	spawnAura = false;

	contadorMovimiento = contadorQuieto= 0;
	actualizaMov = true;
	nuevaPosicion();
}


LittleSpider::~LittleSpider()
{
}

void LittleSpider::update(int delta){
	
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
				miniCarga(pos.first, pos.second, delta, 2);
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

void LittleSpider::animacionBasica(){ //Para el paso de frames
	if (rectAnim.x >= 60){
		rectAnim.x = 0;
	}
	else {
		rectAnim.x += 32;
	}
}

void LittleSpider::nuevaPosicion(){
	srand(time(NULL));

	SDL_Rect rectPlayer;
	rectPlayer = juego->player->getRect();
	directionX = directionY = 0;

	directionX = (rand() % 30 + 1) - 20;		//Rango: [-30, 30] para la velocidad
	directionY = (rand() % 30 + 1) - 20;		//Rango: [-30, 30] para la velocidad
			
			

	int nuevaX = rectPlayer.x + directionX;
	int nuevaY = rectPlayer.y + directionY;
	pair <int, int> nuevaPos = make_pair(nuevaX, nuevaY);

	pos = nuevaPos;
}

void LittleSpider::miniCarga(int x, int y, int delta, int mod){

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
		rect.x -= mod*(vX / 2) * delta;
		rect.y -= mod*(vY / 2) * delta;
	}
	else {
		rect.x += mod*(vX / 2) * delta / 1.5f;
		rect.y += mod*(vY / 2) * delta / 1.5f;
	}


}