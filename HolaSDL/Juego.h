#pragma once
#include <vector>
#include <string>
#include <stack>

#include "SDL.h"

#include "Textura.h"
#include "EstadoJuego.h"
#include "ObjetoJuego.h"

#include "Musica.h"

using namespace std;



//860 460
class Juego
{
public:

	Juego();
	~Juego();

	//SCREEN (WINDOW) DIMENSIONS
	int const SCREEN_WIDTH = 680;
	int const SCREEN_HEIGHT = 480;

	//TEXTURE TYPES
	enum Texturas_t {
		TPlayer, TBulletPlayer, TBExit, TBPlay, TBMenu, TBResume,
		TEnemy, TBulletEnemy, TVidaLlena, TVidaVacia, TDashLleno,
		TDashVacio, TCargador, TDialogo, TCheck, TEnemyPlanta
	};

	//PUBLIC VARIABLES
	SDL_Renderer* pRenderer;
	SDL_Window* pWindow;
	SDL_Color pcolor;
	Textura * pTexture;
	SDL_Event e;

	int x, y;
	bool exit;


	//GAME TIME (GLOBAL)
	float delta;

	//VELOCITY (PLAYER)
	static const int VPLAYER = 10;
	int mVelX, mVelY;

	//STATE MANAGER
	EstadoJuego* estado;
	std::stack<EstadoJuego*> states;

	//STACK
	void changeState(EstadoJuego* newSt);
	void pushState(EstadoJuego* newState);
	void popState();
	EstadoJuego* topEstado();

	//GLOBAL ARRAYS
	std::vector<ObjetoJuego*> arrayObjetos;
	std::vector<ObjetoJuego*> arrayMenu;
	std::vector<int> stats;
	
	//CAMERA LEVEL
	SDL_Rect camera;	
	
	//INITS
	bool initSDL();
	bool initMedia();

	//GAME MANAGER FUNCTIONS
	void run();
	void handle_events();
	void updateDirection();
	
	bool checkCollision(ObjetoJuego * a, ObjetoJuego * b);
	bool touchesWall(ObjetoJuego * a);
	bool checkWallCollisions(ObjetoJuego * a, SDL_Rect b);
	
	//CLOSERS
	void setSalir(){ exit = true; }
	void freeMedia();
	void closeSDL();

	//GETTERS
	SDL_Renderer* getRender() const { return pRenderer; }
	SDL_Rect getCamera(){ return camera; }
	Textura* getTextura(Texturas_t et) const { return arrayTex[et]; }
	void getMousePos(int & mpx, int & mpy) const;
	int getHeight() const;
	int getWidth() const;
	int getVelX();
	int getVelY();

	//MUSIC
	enum MusicIds { Cancion1, };
	//FONTS
	enum Fuentes { Arial, };
	string getTexto(int fun) { return nombreFuentes[fun]; }

private:
	
	//ARRAYS
	std::vector<std::string> texturas;
	std::vector<Textura*> arrayTex;
	///TEXT
	std::vector<Texto> arrayFuentes;
	std::vector<string> nombreFuentes;
	///MUSIC	
	vector <string> musicNames;//Vector para almacenar direcciones de canciones
	Musica* cancion; //Auxiliar para llenar el vector de musica
	vector <Musica*> musicFiles;

	Texto textoAux;
};

