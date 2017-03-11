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

	exit = false;

	arrayTex.resize(5);

	initSDL();
	initMedia();

	changeState(new Play(this));
	estado = topEstado(); //primer estado: MENU

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
			}
			// else if(...)    
		}
	updateDirection();
	if (e.type == SDL_KEYUP) {
		if (e.key.keysym.sym == SDLK_ESCAPE && dynamic_cast<Play*>(topEstado()) != nullptr) {
				pushState(new Pausa(this));
		}
	}

	}
}

void Juego::updateDirection() {

	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY -= VPLAYER; break;
		case SDLK_DOWN: mVelY += VPLAYER; break;
		case SDLK_LEFT: mVelX -= VPLAYER; break;
		case SDLK_RIGHT: mVelX += VPLAYER; break;
		}
	}

	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY += VPLAYER; break;
		case SDLK_DOWN: mVelY -= VPLAYER; break;
		case SDLK_LEFT: mVelX += VPLAYER; break;
		case SDLK_RIGHT: mVelX -= VPLAYER; break;
		}
	}
	/*if (e.type == SDL_KEYDOWN) {
		if (e.key.keysym.sym == SDLK_w || e.key.keysym.sym == SDLK_UP) {
			tecla = 'w';
		}
		else if (e.key.keysym.sym == SDLK_a || e.key.keysym.sym == SDLK_LEFT) {
			tecla = 'a';
		}
		else if (e.key.keysym.sym == SDLK_d || e.key.keysym.sym == SDLK_RIGHT) {
			tecla = 'd';
		}
		else if (e.key.keysym.sym == SDLK_s || e.key.keysym.sym == SDLK_DOWN) {
			tecla = 's';
		}
	}
	else tecla = 'ñ';*/
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
	for (size_t aux = 0; aux < arrayTex.size(); ++aux) {
		arrayTex[aux] = new Textura;
		bool error = arrayTex[aux]->load(pRenderer, "..\\bmps\\textura" + to_string(aux) + ".png");
		if (error) throw Error("Textura no cargada");
	}
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

int Juego::getVelX() { return mVelX; }
int Juego::getVelY() { return mVelY; }

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