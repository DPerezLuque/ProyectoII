#include "Player.h"
#include <algorithm>


Player::Player(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TPlayer);
	
	rect.w = 100;
	rect.h = 100;

	velX = 0;
	velY = 0;

	estJugador = QUIETO;

	//tiempoMaxDash = SDL_AddTimer(0.3, resetPlayerVel(), nullptr);
}


Player::~Player()
{
}

//Bueno básicamente vamos a aplicar newton al código. Necesito un enum de direcciones del jugador y que esas direcciones sean lo que le sumas, restas etc. 
//Luego tenemos un modulo de la velocidad que es la del jugador media?? y el enum de lo que esta haciendo lo pudedes igualar a números que va a ser lo que multipliques
//Usamos una specie de velocidad por el angulo, para las diagonales, por el tiempo del procesador
//Y el direccion es, sorpresa sorpresa, las direcciones
void Player::update(int delta) {

	//movimientoYDash(evento);

	//rect.x += velX;
	//rect.y += velY;

	modulo_vel =  estJugador;

	rect.x += modulo_vel * cos((direccion*M_PI)/180) * delta;
	rect.y += modulo_vel * sin((direccion*M_PI) / 180) * delta;

	//Reset del movimiento
	if (estJugador == DASH)			
			estJugador = ANDANDO;
} 

bool Player::onClick() {
	
	static_cast <Play*> (juego->topEstado())->newDisparo(this, rect.x, rect.y);
	return true;
}

//Método que controla el movimiento y el dash en el down de la tecla
void Player::movimientoDown(SDL_Event evento){

	//Cuando el jugador pulse una tecla...
	if (evento.key.repeat == 0)
	{

		if (estJugador == QUIETO) {
			direccion = NoDir;

			//Ajustamos la velocidad en función de la tecla pulsada, a excepcion del espacio que hace un dash
			switch (evento.key.keysym.sym)
			{
				//Arriba//
			case SDLK_i: //Teclado zurdos de los cojones

				//if (direccion = Este) direccion = NorEste;
				//else if (direccion = Oeste) direccion = NorOeste;
				 direccion = Norte;
				//Ponemos al jugador en movimiento
				estJugador = ANDANDO;
				break;

			case SDLK_w:
				//Comprobamos el ángulo del jugador
				//if (direccion = Este) direccion = NorEste;
				//else if (direccion = Oeste) direccion = NorOeste;
				 direccion = Norte;

				//Ponemos al jugador en movimiento
				estJugador = ANDANDO;
				break;

				//Abajo//
			case SDLK_k: //Teclado zurdos
				//if (direccion = Este) direccion = SurEste;
				//else if (direccion = Oeste) direccion = SurOeste;
				 direccion = Sur;

				//Ponemos al jugador en movimiento
				estJugador = ANDANDO;
				break;
			case SDLK_s:

				//if (direccion = Este) direccion = SurEste;
				//else if (direccion = Oeste) direccion = SurOeste;
				 direccion = Sur;

				//Ponemos al jugador en movimiento
				estJugador = ANDANDO;
				break;

				//Izquierda//
			case SDLK_j: //Teclado zurdos

				//if (direccion = Norte) direccion = NorOeste;
				//else if (direccion = Sur) direccion = SurOeste;
				 direccion = Oeste;

				//Ponemos al jugador en movimiento
				estJugador = ANDANDO;
				break;

			case SDLK_a:

				//if (direccion = Norte) direccion = NorOeste;
				//else if (direccion = Sur) direccion = SurOeste;
				  direccion = Oeste;

				//Ponemos al jugador en movimiento
				estJugador = ANDANDO;
				break;

				//Derecha
			case SDLK_l: //Teclado zurdos

				//if (direccion = Norte) direccion = NorEste;
				//else if (direccion = Sur) direccion = SurEste;
				  direccion = Este;

				//Ponemos al jugador en movimiento
				estJugador = ANDANDO;
				break;

			case SDLK_d:

				//if (direccion = Norte) direccion = NorEste;
				//else if (direccion = Sur) direccion = SurEste;
				  direccion = Este;

				//Ponemos al jugador en movimiento
				estJugador = ANDANDO;
				break;

				//Espacio
			case SDLK_SPACE:	// ACTUA COMO MODIFICADOR DEL MOVIMIENTO

				//if ( estJugador==ANDANDO)
				estJugador = DASH;

				break;

			} // Switch ()
		}
	}

}

void Player::movimientoUp(SDL_Event evento) {

	estJugador = QUIETO;
	
}
