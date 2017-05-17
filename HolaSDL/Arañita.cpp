#include "Arañita.h"


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

		if (contadorMovimiento >= 80){

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
