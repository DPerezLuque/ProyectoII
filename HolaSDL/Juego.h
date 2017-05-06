#pragma once
#include <vector>
#include <string>
#include <stack>

#include "SDL.h"

#include "Textura.h"
#include "EstadoJuego.h"
#include "ObjetoJuego.h"

#include "Musica.h"

//using namespace std;

//860 460
class Juego
{
public:

	Juego();
	~Juego();

	//SCREEN (WINDOW) DIMENSIONS	//680x480
	int const SCREEN_WIDTH = 1000;
	int const SCREEN_HEIGHT = 750;

	//TEXTURE TYPES
	enum Texturas_t {
		TPlayer, TBulletPlayer, TBExit, TBPlay, TBMenu, TBResume,
		TEnemy, TBulletEnemy, TVidaLlena, TVidaVacia, TDashLleno,
		TDashVacio, TCargador, TDialogo, TCheck, TEnemyPlanta, TBarraVida, THumo,
		TBotiquin, TPapelera1, TPapelera2, TPapelera3, TMesaEE, 
		TMesa, TMesaCorazon, TMesaTentaculo, TMesaDoble, TMesaRota, TMesaRota2,
		TBobina, TAura, TPlanta1, TPlanta2, TPlanta3,
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
	std::vector<ObjetoJuego*> arrayObjetos;		//ALL OBJECTS IN THE SCENE (DYNAMIC)
	std::vector<ObjetoJuego*> enemyArray;		//ENEMIGOS
	std::vector<ObjetoJuego*> playerBullets;	//BALAS PERSONAJE
	std::vector<ObjetoJuego*> enemyBullets;		//BALAS ENEMIGOS 
	std::vector<ObjetoJuego*> arrayMenu;
	std::vector<ObjetoJuego*> objVisible;
	
	//std::vector<int> stats;

	//PLAYER
	ObjetoJuego * player;

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
	bool touchesWall(SDL_Rect a);
	bool checkWallCollisions(SDL_Rect a, SDL_Rect b);

	//CLOSERS
	void setSalir(){ exit = true; }
	void freeMedia();
	void closeSDL();
	
	//SETTERS
	bool isInScreen(SDL_Rect rect);
	void addToScreen(ObjetoJuego * obj);
	//void addToScreen(Tilemap::Tile * t);

	//GETTERS
	SDL_Renderer* getRender() const { return pRenderer; }
	SDL_Rect getCamera(){ return camera; }
	Textura* getTextura(Texturas_t et) const { return arrayTex[et]; }
	void getMousePos(int & mpx, int & mpy) const;
	int getHeight() const {return SCREEN_HEIGHT;}
	int getWidth() const {	return SCREEN_WIDTH;}
	int getVelX(){ return mVelX; }
	int getVelY(){ return mVelY; }
	bool getDash(){ return dashing; }
	void setDash(bool dash){ dashing = dash; }

	//CREA COSAS
	void creaAlmas(int, int, std::string);
	void spawnObjetos(char, int, int, std::string);	//Identificador, posicionX, posicionY, String por si es un alma (opcional)

	//MUSIC
	enum MusicIds { Cancion1, };
	//FONTS
	enum Fuentes { Arial, };
	string getTexto(int fun) { return nombreFuentes[fun]; }
	bool dashing = false;
	bool getDASH(){ return dashAux; }
	void setDASH(bool dash){dashAux = dash;	}
	void setRecargar(bool re){ recargar = re; }
	bool getRecargar(){ return recargar; }

private:
	bool dashAux = false;
	bool recargar = false;
	//ARRAYS
	std::vector<std::string> texturas;
	std::vector<Textura*> arrayTex;
	///TEXT
	std::vector<Texto> arrayFuentes;
	std::vector<string> nombreFuentes;
	std::vector<string> VectTextosAlma;
	///MUSIC	
	vector <string> musicNames;//Vector para almacenar direcciones de canciones
	Musica* cancion; //Auxiliar para llenar el vector de musica
	vector <Musica*> musicFiles;

	Texto textoAux;

	
	int contDash;
};

