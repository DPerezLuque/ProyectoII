#include "EnemigoGuardia.h"


#include <random>

EnemigoGuardia::EnemigoGuardia(Juego* ptr, int px, int py) : EnemigoBase(ptr, px, py)
{
	textura = juego->getTextura(Juego::TEnemy);
	vida = 3;
	animado = false;
	contadorFrames = 0;
	animado = true;
	rectAnim = { 0, 0, 64, 64 };
	est = animacion::ABAJO;
	rect.w = 64;
	rect.h = 64;


	radioDisable = 800;
	radioEnable = 400;
}


EnemigoGuardia::~EnemigoGuardia()
{
}


void EnemigoGuardia::update(int delta) 
{	

	if (isActive()) {

		SDL_Rect rectPlayer;
		rectPlayer = juego->player->getRect();

		rectVida.x = rect.x - 20;
		rectVida.y = rect.y - 20;
		rectVida.w = 32 * vida;

		int lastY = rect.y;			//Uso lastY y lastX para calcular en qué dirección
		int lastX = rect.x;			//se está moviendo para cambiar la animación

		follow(rectPlayer.x, rectPlayer.y, delta);
		//(contDis < freDis - 10) ){ //Algo tope chungo para que se pare al disparar << no hace falta
		contDis += delta;

		//ANIMACIÓN
		int restaY = lastY - rect.y;
		int restaX = lastX - rect.x;

		if (abs(restaY) >= abs(restaX)) {
			if (restaY < 0) {
				//se mueve para abajo
				est = animacion::ABAJO;
			}
			else {
				//se mueve para arriba
				est = animacion::ARRIBA;
			}
		}
		else {
			if (restaX < 0) {
				//se mueve hacia la derecha
				est = animacion::DERECHA;
			}
			else {
				//se mueve hacia la izquierda
				est = animacion::IZQUIERDA;
			}
		}

		contadorFrames += delta;
		if (contadorFrames >= 8) { //Paso de imagenes mas lento
			animar(est);
			contadorFrames = 0;
		}

		//////////

		if (contDis >= freDis) {
			shoot(rectPlayer.x, rectPlayer.y, 'n');
			contDis = 0;
		}

		

		if (inmunidad) {
			if (contInm < 20) contInm++;
			else if (contInm == 20)
			{
				inmunidad = false;
				contInm = 0;
			}
		}
	}
}

void EnemigoGuardia::animacionBasica()
{
	if (rectAnim.x >= 192) {
		rectAnim.x = 0;
	}
	else {
		rectAnim.x += 64;
	}
}

void EnemigoGuardia::animar(animacion current)
{
	switch (current)
	{
	case animacion::IZQUIERDA:
		rectAnim.y = 192; //Altura de la animacion		
		break;
	case animacion::DERECHA:
		rectAnim.y = 128;
		break;
	case animacion::ARRIBA:
		rectAnim.y = 64;
		break;
	case animacion::ABAJO:
		rectAnim.y = 0;
		break;
	default:
		break;
	}
	animacionBasica();
}







