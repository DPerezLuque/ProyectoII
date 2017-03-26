#include "SDL.h"
#include "Juego.h"

#include <iostream>
#include <vector>
#include <typeinfo>
#include <stack>

#include "Play.h"
#include "MenuPrincipal.h"
#include "Pausa.h"

#include <exception>
#include "Error.h"

using namespace std;

Juego::Juego()
{
	srand(SDL_GetTicks());

	pWindow = nullptr;
	pRenderer = nullptr;
	pcolor = { 0, 0, 0 }; //Color del fondo negro;

	//Inicialización de bools
	exit = false;
	//hazDash = false;
	
	initSDL();
	initMedia();

	changeState(new Play(this));
	estado = topEstado(); //primer estado: MENU
	dashX = dashY = 0;
	

}

Juego::~Juego()
{
	estado = nullptr;
	freeMedia();
	closeSDL();
}


void Juego::run()
{
	Uint32 MSxUpdate = 25;
	cout << "PLAY \n";
	Uint32 lastUpdate = SDL_GetTicks();

	estado->draw();
	handle_events();

	while (!exit) {
		//estado = topEstado();
		if (SDL_GetTicks() - lastUpdate >= MSxUpdate){ //while(elapsed >= MSxUpdate)
			estado->update();
			lastUpdate = SDL_GetTicks();
		}
		estado = topEstado();
		estado->draw();
		handle_events();
		
	}

	if (exit) cout << "EXIT \n";
	else {
		estado->draw();
	}
	SDL_Delay(1000); //cin.get();
}


void Juego::handle_events()
{
	if (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) setSalir();
		else if (e.type == SDL_MOUSEBUTTONUP) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				//std::cout << "CLICK";
				x = e.button.x;
				y = e.button.y;
				estado->onClick();
				dashDisponible = false;
			}
			 
		}
		
		
		updateDirection();
		if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym == SDLK_ESCAPE && dynamic_cast<Play*>(topEstado()) != nullptr) {
					pushState(new Pausa(this));
			}
		}

	}
}
//Toda la lógica de control de movimiento DEL JUGADOR está en este método. 
	//Consiste en un switch que comprueba qué tecla se ha pulsado, y en funcion de la tecla se mueve a una dirección u otra.
	//Cuando se pulsa el espacio, se efectua el dash 
void Juego::updateDirection() {

	int d = 30;						//Variable que se añade o resta a la velocidad del jugador para el dash

	//Cuando el jugador pulse una tecla...
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{

		//Ajustamos la velocidad en función de la tecla pulsada, a excepcion del espacio que hace un dash
		switch (e.key.keysym.sym)
		{
		//Arriba
		case SDLK_i: //Teclado zurdos

			mVelY -= VPLAYER;

			break;
		case SDLK_w:

			mVelY -= VPLAYER;

			break;

		//Abajo
		case SDLK_k: //Teclado zurdos

			mVelY += VPLAYER;

			break;
		case SDLK_s:

			mVelY += VPLAYER;

			break;

		//Izquierda
		case SDLK_j: //Teclado zurdos

			mVelX -= VPLAYER;

			break;

		case SDLK_a:

			mVelX -= VPLAYER;

			break;

		//Derecha
		case SDLK_l: //Teclado zurdos

			mVelX += VPLAYER;

			break;

		case SDLK_d:

			mVelX += VPLAYER;

			break;

		//Espacio
		case SDLK_SPACE:	// ACTUA COMO MODIFICADOR DEL MOVIMIENTO

			if (dashDisponible) {					//La variable se modifica cuando se SUELTA el botón		(Debería ser false??)

				if (mVelX > 0 && mVelX <= d ) {					// Cuando vas a la derecha (Right o D) Y SUELTAS EL BOTÓN DE ESPACIO
					dashDisponible = false;			
					if (mVelY != 0) {				//Regulamos las direcciones en diagonal
						if (mVelY > 0 && mVelY <= d) {

							mVelY += (d / 2);
						}
						else if (mVelY < 0 && mVelY >= -d)
							mVelY -= (d / 2);
						// Cantidad fija a la X
						mVelX += (d / 2);
					}
					else
					{
						mVelX += d;						//Cuando no vas en diagonal
					}	
				}

				else if (mVelX < 0 && mVelX >= -d) {				// Cuando vas a la izquierda (Left o A)
					dashDisponible = false;
					if (mVelY != 0) {				//Regulamos las direcciones en diagonal
						if (mVelY > 0 && mVelY <= d) {

							mVelY += (d / 2);
						}
						else if (mVelY < 0 && mVelY >= -d)
							mVelY -= (d / 2);
						// Cantidad fija a la X
						mVelX -= (d / 2);					//Cuando no vas en diagonal
					}
					else
					{
						mVelX -= d;
					}
				}

				else if (mVelY > 0 && mVelY <= d) {					// Cuando vas abajo (Down o S) Y SUELTAS EL PUTO BOTON
					dashDisponible = false;
					mVelY += d;
				}



				else if (mVelY < 0 && mVelY >= -d) {				// Cuando vas arriba (Up o W)
					dashDisponible = false;
					mVelY -= d;

				}
				break;
				
			}

			else
			{
				break;    //Si el jugador ya se ha desplazado con dash, no puede volver a hacerlo y se le expulsará hasta que suelte el espacio.			(Esto aún no funciona pero esa es la idea)
			}



		} // Switch ()
	}


	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
	
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
			//Arriba
			case SDLK_i: //Teclado zurdos
				mVelY += VPLAYER;
			
				break;

			case SDLK_w:
				mVelY += VPLAYER;
			
				break;

			//Abajo
			case SDLK_k: //Teclado zurdos
				mVelY -= VPLAYER;
		
				break;
			case SDLK_s:
				mVelY -= VPLAYER;
			
				break;

			//Izquierda
			case SDLK_j: //Teclado zurdos
				mVelX += VPLAYER;
			
				break;
			case SDLK_a:
				mVelX += VPLAYER;
		
				break;

			//Derecha
			case SDLK_l: //Teclado zurdos
				mVelX -= VPLAYER;
		
				break;
			case SDLK_d:
				mVelX -= VPLAYER;
		
				break;

				//Espacio
			case SDLK_SPACE:

				if (mVelX > 0 && mVelX <= d) {						// Cuando vas a la derecha (Right o D) Y SUELTAS EL BOTÓN DE ESPACIO
					dashDisponible = true;
					if (mVelY != 0) {		//Regulamos las direcciones en diagonal
						if (mVelY > 0 && mVelY <= d) {
						
							mVelY -= (d / 2);
						}
						else if (mVelY < 0 && mVelY >= -d)
							mVelY += (d / 2);
						// Cantidad fija a la X
						mVelX -= (d / 2);
					}
					else
					{
						mVelX -= d;
					}
				}

				else if (mVelX < 0) {				// Cuando vas a la izquierda (Left o A)
					dashDisponible = true;
					if (mVelY != 0) {		//Regulamos las direcciones en diagonal
						if (mVelY > 0 && mVelY <= d) {

							mVelY -= (d / 2);
						}
						else if (mVelY < 0 && mVelY >= -d)
							mVelY += (d / 2);
						// Cantidad fija a la X
						mVelX += (d / 2);
					}
					else
					{
						mVelX += d;
					}
				}

				else if (mVelY > 0 && mVelY <= d) {					// Cuando vas abajo (Down o S) Y SUELTAS EL PUTO BOTON
					dashDisponible = true;
					mVelY -= d;
				}
			
			

				else if (mVelY < 0 && mVelY >= -d) {				// Cuando vas arriba (Up o W)
					dashDisponible = true;
					mVelY += d;
		
				}
				break;
			}
		
	}
}

//Método que comprueba si en la dirección en la que apuntamos el dash tiene colisiones
bool Juego::compruebaDash(){

	return true;
}

void Juego::initSDL()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		throw Error("SDL no ha podido inicializar");
		cout << "SDL could not initialize! \nSDL_Error: " << SDL_GetError() << '\n';
	}
	else {
		//Create window: SDL_CreateWindow("SDL Hello World", posX, posY, width, height, SDL_WINDOW_SHOWN);
		pWindow = SDL_CreateWindow("Pincha Globos", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (pWindow == nullptr) {
			throw Error("La ventana no se ha podido crear");
			cout << "Window could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
		}
		else {
			//Get window surface:
			pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
			//SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255); //Set background color to black 
			if (pRenderer == nullptr) {
				throw Error("El renderizador no se ha podido crear");
				cout << "Renderer could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
			}
		}
	}
}

void Juego::initMedia()
{
	texturas.push_back("..\\bmps\\personaje.png");
	texturas.push_back("..\\bmps\\bala.png");
	texturas.push_back("..\\bmps\\menu_salir.png");
	texturas.push_back("..\\bmps\\menu_play.png");
	texturas.push_back("..\\bmps\\menu_menu.png");
	texturas.push_back("..\\bmps\\menu_resume.png");
	

	//Cargamos las texturas (fondo, globos, mariposas y premio)
	for (int j = 0; j < texturas.size(); ++j) {

		pTexture = new Textura;
		pTexture->load(pRenderer, texturas[j]);
		arrayTex.push_back(pTexture);
	}
	/*
	for (size_t aux = 0; aux < arrayTex.size(); ++aux) {
		arrayTex[aux] = new Textura;
		bool error = arrayTex[aux]->load(pRenderer, "..\\bmps\\textura" + to_string(aux) + ".png");
		if (error) throw Error("Textura no cargada");
	}
	*/
}


void Juego::setSalir() { exit = true; }

void Juego::freeMedia()
{	
	for (size_t aux = 0; aux < arrayTex.size(); ++aux) {
		delete arrayTex[aux];
		arrayTex[aux] = nullptr;
	}
}

void Juego::closeSDL()
{
	SDL_DestroyRenderer(pRenderer);
	pRenderer = nullptr;

	SDL_DestroyWindow(pWindow);
	pWindow = nullptr;

	SDL_Quit();
}

//////////////////// GETTERS /////////////////////
void Juego::getMousePos(int & mpx, int & mpy) const
{
	mpx = x;
	mpy = y;
}

int Juego::getHeight() const
{
	return SCREEN_HEIGHT;
}

int Juego::getWidth() const
{
	return SCREEN_WIDTH;
}

int Juego::getVelX() { 
	
	return mVelX; 
}
int Juego::getVelY() {
	
	return mVelY;
}

////////////////// PILA ///////////////////////////
void Juego::changeState(EstadoJuego* newSt)
{
	if (!states.empty()) popState(); //si no está vacía, se vacía
	pushState(newSt); //se mete el nuevo estado
} 

void Juego::pushState(EstadoJuego* newState)
{
	states.push(newState);
}

void Juego::popState() 
{
	delete states.top();
	states.pop();
}

EstadoJuego* Juego::topEstado() { return states.top();  }