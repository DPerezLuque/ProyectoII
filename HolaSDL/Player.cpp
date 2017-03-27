#include "Player.h"



Player::Player(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TPlayer);
	
	rect.w = 100;
	rect.h = 100;

	velX = 0;
	velY = 0;

}


Player::~Player()
{
}

void Player::update() {

	evento = juego->getEvent();

	movimientoYDash(evento);

} 

bool Player::onClick() {
	
	static_cast <Play*> (juego->topEstado())->newDisparo(this, rect.x, rect.y);
	return true;
}

void Player::movimientoYDash(SDL_Event evento){

	int d = DASH;						//Variable que se a�ade o resta a la velocidad del jugador para el dash

	//Cuando el jugador pulse una tecla...
	if (evento.type == SDL_KEYDOWN && evento.key.repeat == 0)
	{

		//Ajustamos la velocidad en funci�n de la tecla pulsada, a excepcion del espacio que hace un dash
		switch (evento.key.keysym.sym)
		{
			//Arriba
		case SDLK_i: //Teclado zurdos

			velY -= VPLAYER;

			break;
		case SDLK_w:

			velY -= VPLAYER;

			break;

			//Abajo
		case SDLK_k: //Teclado zurdos

			velY += VPLAYER;

			break;
		case SDLK_s:

			velY += VPLAYER;

			break;

			//Izquierda
		case SDLK_j: //Teclado zurdos

			velX -= VPLAYER;

			break;

		case SDLK_a:

			velX -= VPLAYER;

			break;

			//Derecha
		case SDLK_l: //Teclado zurdos

			velX += VPLAYER;

			break;

		case SDLK_d:

			velX += VPLAYER;

			break;

			//Espacio
		case SDLK_SPACE:	// ACTUA COMO MODIFICADOR DEL MOVIMIENTO



			if (velX > 0 && velX <= d) {					// Cuando vas a la derecha (Right o D) Y SUELTAS EL BOT�N DE ESPACIO

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

	} // Switch ()

	//If a key was released
	else if (evento.type == SDL_KEYUP && evento.key.repeat == 0)
	{

		//Adjust the velocity
		switch (evento.key.keysym.sym)
		{
			//Arriba
		case SDLK_i: //Teclado zurdos
			velY += VPLAYER;

			break;

		case SDLK_w:
			velY += VPLAYER;

			break;

			//Abajo
		case SDLK_k: //Teclado zurdos
			velY -= VPLAYER;

			break;
		case SDLK_s:
			velY -= VPLAYER;

			break;

			//Izquierda
		case SDLK_j: //Teclado zurdos
			velX += VPLAYER;

			break;
		case SDLK_a:
			velX += VPLAYER;

			break;

			//Derecha
		case SDLK_l: //Teclado zurdos
			velX -= VPLAYER;

			break;
		case SDLK_d:
			velX -= VPLAYER;

			break;

			//Espacio
		case SDLK_SPACE:

			if (velX > 0 && velX <= d) {						// Cuando vas a la derecha (Right o D) Y SUELTAS EL BOT�N DE ESPACIO

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
			break;
		}

	}

}
