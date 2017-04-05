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
#include "MapEditor.h"

#include <SDL_mixer.h>
#include <SDL_ttf.h>

using namespace std;

//The level tiles
Tilemap::Tile* tileSet[TOTAL_TILES];


Juego::Juego()
{
	//Música
	Mix_Init(27);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	Mix_Volume(1, MIX_MAX_VOLUME / 2);
	//Texto
	TTF_Init();

	srand(SDL_GetTicks());

	pWindow = nullptr;
	pRenderer = nullptr;
	pcolor = { 0, 0, 0 }; //Color del fondo negro;

	exit = false;

	if (!initSDL())
	{
		printf("Failed to initialize!\n");
	}
	else if (!initMedia())
	{
		printf("Failed to load media!\n");
	}
	else 
	{
		camera = { 0, 0, 860, 480 };
		changeState(new Play(this));
		estado = topEstado(); //primer estado: MENU
	}
}

Juego::~Juego()
{
	estado = nullptr;
	freeMedia();
	Mix_Quit(); //Musica
	TTF_Quit(); //Texto
	closeSDL();
}


void Juego::run()
{
	Uint32 MSxUpdate = 25;
	cout << "PLAY \n";
	Uint32 lastUpdate = SDL_GetTicks();

	//Clear screen	
	SDL_RenderClear(pRenderer);

	//Render level
	for (int i = 0; i < TOTAL_TILES; ++i)
	{
		tileSet[i]->render(pRenderer, camera);
	}

	//Update screen
	SDL_RenderPresent(pRenderer);

	estado->draw();
	handle_events();

	while (!exit) {
		//estado = topEstado();
		if (SDL_GetTicks() - lastUpdate >= MSxUpdate){ //while(elapsed >= MSxUpdate)
			estado->update();
			lastUpdate = SDL_GetTicks();
		}
		estado = topEstado();
		//Render level
		for (int i = 0; i < TOTAL_TILES; ++i)
		{
			tileSet[i]->render(pRenderer, camera);
		}

		estado->draw();
		handle_events();
	}

	if (exit) cout << "EXIT \n";
	else {
		estado->draw();
	}
	SDL_Delay(1000); //cin.get();
}
/*

//Render level
//Clear screen
SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
SDL_RenderClear(pRenderer);

//Render level
for (int i = 0; i < TOTAL_TILES; ++i)
{
tileSet[i]->render(camera);
}

//Update screen
SDL_RenderPresent(pRenderer);
*/

bool Juego::initSDL()
{
	
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		pWindow = SDL_CreateWindow("Proyecto II", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (pWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (pRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool Juego::initMedia()
{
	bool success = true;	

	//musicFiles[0] = new Musica("..\\Sonidos\\Musica\\Come.ogg");
	//musicFiles[0]->load("..\\Sonidos\\Musica\\Come.Mp3");
	//musicFiles[0]->play();

	//effectFile = new Efecto("..\\Sonidos\\Efectos\\Come.wav");
	//effectFile->play();

	musicNames.push_back("..\\Sonidos\\Musica\\Come.mp3");
	//musicNames.push_back("..\\Sonidos\\Efectos\\Come.wav");

	for (int j = 0; j < musicNames.size(); ++j) {
		cancion = new Musica;
		cancion->load(musicNames[j]);		
		musicFiles.push_back(cancion);		
	}

	musicFiles[Come]->play();

	textoDePrueba.load("..\\Fuentes\\ARIAL.ttf", 20);
	cosaDePrueba = new Textura();
	Black = { 0, 0, 0 };
	cosaDePrueba->loadFromText(pRenderer, "Hola que tal", textoDePrueba,Black);
	rectamgulon = {15, 15, 300, 300};
	cosaDePrueba->draw(pRenderer, rectamgulon);

	texturas.push_back("..\\bmps\\personaje.png");
	texturas.push_back("..\\bmps\\bala.png");
	texturas.push_back("..\\bmps\\menu_salir.png");
	texturas.push_back("..\\bmps\\menu_play.png");

	texturas.push_back("..\\bmps\\menu_menu.png");
	texturas.push_back("..\\bmps\\menu_resume.png");
	texturas.push_back("..\\bmps\\enemy.png");
	texturas.push_back("..\\bmps\\balaEnemigo.png");
	//Interfaz
	texturas.push_back("..\\bmps\\VidaLlena.png");
	texturas.push_back("..\\bmps\\VidaVacia.png");
	texturas.push_back("..\\bmps\\DashLleno.png");
	texturas.push_back("..\\bmps\\DashVacio.png");
	texturas.push_back("..\\bmps\\Cargador.png");


	//Load Assets Textures
	for (int j = 0; j < texturas.size(); ++j) {
		pTexture = new Textura;
		pTexture->load(pRenderer, texturas[j]);
		arrayTex.push_back(pTexture);	
	}

	//Load tile texture
	if (!gTileTexture.loadFromFile(pRenderer, "..\\bmps\\sheet2.png"))
	{
		printf("Failed to load tile set texture!\n");
		success = false;
	}

	//Load tile map
	if (!setTiles(tileSet))
	{
		printf("Failed to load tile set!\n");
		success = false;
	}

	return success;
}


void Juego::setSalir() { exit = true; }

void Juego::freeMedia()
{	
	for (size_t aux = 0; aux < arrayTex.size(); ++aux) {
		delete arrayTex[aux];
		//arrayTex[aux] = nullptr;
	}
}

void Juego::closeSDL()
{
	for (int i = 0; i < TOTAL_TILES; ++i)
	{
		if (tileSet[i] == NULL)
		{
			delete tileSet[i];
			tileSet[i] = NULL;
		}
	}

	//Free loaded images
	gTileTexture.free();

	//Destroy window	
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	pWindow = NULL;
	pRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
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
		case SDLK_w: mVelY -= VPLAYER; break;

		case SDLK_DOWN: mVelY += VPLAYER; break;
		case SDLK_s: mVelY += VPLAYER; break;

		case SDLK_LEFT: mVelX -= VPLAYER; break;
		case SDLK_a: mVelX -= VPLAYER; break;

		case SDLK_RIGHT: mVelX += VPLAYER; break;
		case SDLK_d: mVelX += VPLAYER; break;
		}
	}

	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY += VPLAYER; break;
		case SDLK_w: mVelY += VPLAYER; break;

		case SDLK_DOWN: mVelY -= VPLAYER; break;
		case SDLK_s: mVelY -= VPLAYER; break;

		case SDLK_LEFT: mVelX += VPLAYER; break;
		case SDLK_a: mVelX += VPLAYER; break;

		case SDLK_RIGHT: mVelX -= VPLAYER; break;
		case SDLK_d: mVelX -= VPLAYER; break;
		}
	}
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