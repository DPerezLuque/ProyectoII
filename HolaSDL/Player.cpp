#include "Player.h"



Player::Player(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TPlayer);
	
	rect.w = 100;
	rect.h = 100;

	velX = 0;
	velY = 0;

	estJugador = QUIETO;

	tiempoMaxDash = SDL_AddTimer(0.3, resetPlayerVel(), nullptr);
}


Player::~Player()
{
}

void Player::update(int delta) {

	//movimientoYDash(evento);

	rect.x += velX;
	rect.y += velY;

	typedef enum {STOPPED = 0, WALK = 4, DASH = 12};

	rect.x += modulo_vel * cos(angulo) * delta;
	rect.y += modulo_vel * sin(angulo) * delta;
} 

bool Player::onClick() {
	
	static_cast <Play*> (juego->topEstado())->newDisparo(this, rect.x, rect.y);
	return true;
}

//Método que controla el movimiento y el dash en el down de la tecla
void Player::movimientoDown(SDL_Event evento){

	int d = DASH;						//Variable que se añade o resta a la velocidad del jugador para el dash

	//Cuando el jugador pulse una tecla...
	if (evento.key.repeat == 0)
	{

		if (estJugador == QUIETO || estJugador == ANDANDO){

			//Ajustamos la velocidad en función de la tecla pulsada, a excepcion del espacio que hace un dash
			switch (evento.key.keysym.sym)
			{
				//Arriba
			case SDLK_i: //Teclado zurdos

				velY -= VPLAYER;
				estJugador = ANDANDO;
				break;
			case SDLK_w:

				velY -= VPLAYER;
				estJugador = ANDANDO;
				break;

				//Abajo
			case SDLK_k: //Teclado zurdos

				velY += VPLAYER;
				estJugador = ANDANDO;
				break;
			case SDLK_s:

				velY += VPLAYER;
				estJugador = ANDANDO;
				break;

				//Izquierda
			case SDLK_j: //Teclado zurdos

				velX -= VPLAYER;
				estJugador = ANDANDO;
				break;

			case SDLK_a:

				velX -= VPLAYER;
				estJugador = ANDANDO;
				break;

				//Derecha
			case SDLK_l: //Teclado zurdos

				velX += VPLAYER;
				estJugador = ANDANDO;
				break;

			case SDLK_d:

				velX += VPLAYER;
				estJugador = ANDANDO;
				break;

				//Espacio
			case SDLK_SPACE:	// ACTUA COMO MODIFICADOR DEL MOVIMIENTO

				if (estJugador == ANDANDO){
					estJugador = DASHEANDO;

					if (velX > 0 && velX <= d) {					// Cuando vas a la derecha (Right o D) Y SUELTAS EL BOTÓN DE ESPACIO

						if (velY != 0) {				//Regulamos las direcciones en diagonal
							if (velY > 0 && velY <= d) {

								velY += (d / 2);
							}
							else if (velY < 0 && velY >= -d)
								velY -= (d / 2);
							// Cantidad fija a la X
							velX += (d / 2);
						}
						else
						{
							velX += d;						//Cuando no vas en diagonal
						}
					}

					else if (velX < 0 && velX >= -d) {				// Cuando vas a la izquierda (Left o A)

						if (velY != 0) {				//Regulamos las direcciones en diagonal
							if (velY > 0 && velY <= d) {

								velY += (d / 2);
							}
							else if (velY < 0 && velY >= -d)
								velY -= (d / 2);
							// Cantidad fija a la X
							velX -= (d / 2);					//Cuando no vas en diagonal
						}
						else
						{
							velX -= d;
						}
					}

					else if (velY > 0 && velY <= d) {					// Cuando vas abajo (Down o S) Y SUELTAS EL PUTO BOTON

						velY += d;
					}



					else if (velY < 0 && velY >= -d) {				// Cuando vas arriba (Up o W)

						velY -= d;

					}
					break;

				}
			}

		} // Switch ()

	}

}

void Player::movimientoUp(SDL_Event evento) {

	int d = DASH;						//Variable que se añade o resta a la velocidad del jugador para el dash

	//If a key was released
	if (evento.key.repeat == 0)
	{

		//Adjust the velocity
		switch (evento.key.keysym.sym)
		{
			//Arriba
		case SDLK_i: //Teclado zurdos
			velY += VPLAYER;
			estJugador = QUIETO;
			break;

		case SDLK_w:
			velY += VPLAYER;
			estJugador = QUIETO;
			break;

			//Abajo
		case SDLK_k: //Teclado zurdos
			velY -= VPLAYER;
			estJugador = QUIETO;
			break;

		case SDLK_s:
			velY -= VPLAYER;
			estJugador = QUIETO;
			break;

			//Izquierda
		case SDLK_j: //Teclado zurdos
			velX += VPLAYER;
			estJugador = QUIETO;
			break;

		case SDLK_a:
			velX += VPLAYER;
			estJugador = QUIETO;
			break;

			//Derecha
		case SDLK_l: //Teclado zurdos
			velX -= VPLAYER;
			estJugador = QUIETO;
			break;

		case SDLK_d:
			velX -= VPLAYER;
			estJugador = QUIETO;
			break;

			//Espacio
		case SDLK_SPACE:

			if (estJugador == DASHEANDO){

				if (velX > 0 && velX <= d) {					// Cuando vas a la derecha (Right o D) Y SUELTAS EL BOTÓN DE ESPACIO

					if (velY != 0) {		//Regulamos las direcciones en diagonal
						if (velY > 0 && velY <= d) {

							velY -= (d / 2);
						}
						else if (velY < 0 && velY >= -d)
							velY += (d / 2);
						// Cantidad fija a la X
						velX -= (d / 2);
					}
					else
					{
						velX -= d;
					}
				}

				else if (velX < 0) {				// Cuando vas a la izquierda (Left o A)

					if (velY != 0) {		//Regulamos las direcciones en diagonal
						if (velY > 0 && velY <= d) {

							velY -= (d / 2);
						}
						else if (velY < 0 && velY >= -d)
							velY += (d / 2);
						// Cantidad fija a la X
						velX += (d / 2);
					}
					else
					{
						velX += d;
					}
				}

				else if (velY > 0 && velY <= d) {					// Cuando vas abajo (Down o S) Y SUELTAS EL PUTO BOTON

					velY -= d;
				}



				else if (velY < 0 && velY >= -d) {				// Cuando vas arriba (Up o W)

					velY += d;

				}

				estJugador = QUIETO;
				break;
			}
		}

	}
}
