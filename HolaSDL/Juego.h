#pragma once
#include <vector>
#include <string>
#include <stack>

#include "SDL.h"

#include "Textura.h"
#include "EstadoJuego.h"
#include "ObjetoJuego.h"

#include "Musica.h"
#include "Efecto.h"

//#include "Texto.h"

using namespace std;

//860 460
class Juego
{
public:

	Juego();
	~Juego();

	SDL_Renderer* pRenderer;
	SDL_Window* pWindow;
	SDL_Color pcolor;
	Textura * pTexture;
	
	enum Texturas_t {
		TPlayer, TBulletPlayer, TBExit, TBPlay, TBMenu, TBResume,
		TEnemy, TBulletEnemy,
		TVidaLlena, TVidaVacia, TDashLleno, TDashVacio, TCargador,
	};

	int const SCREEN_WIDTH = 1366; 
	int const SCREEN_HEIGHT = 720; 
	int x, y;
	bool exit;

	float delta; //USING THIS TO CONTROL GAME TIME

	SDL_Event e;
	static const int VPLAYER = 10;
	int mVelX, mVelY;

	EstadoJuego* estado;

	//Level camera
	SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	
	bool checkCollision(ObjetoJuego * a, ObjetoJuego * b);
	bool touchesWall(ObjetoJuego * a);
	bool checkWallCollisions(ObjetoJuego * a, SDL_Rect b);
	
	std::stack<EstadoJuego*> states;

	///////Pila
	void changeState(EstadoJuego* newSt);
	void pushState(EstadoJuego* newState);
	void popState();
	EstadoJuego* topEstado();
	//Musica
	enum MusicIds { Cancion1, };
	//Fuentes
	enum Fuentes { Arial, };
	Texto getTexto(Fuentes fun) { return arrayFuentes[fun]; }
	Texto getTexto(int num) { return arrayFuentes[num]; }

private:
	//ARRAYS
	std::vector<std::string> texturas;
	std::vector<Textura*> arrayTex;
	//texto
	std::vector<Texto> arrayFuentes;
	std::vector<string> nombreFuentes;
	//Musica	
	vector <string> musicNames;//Vector para almacenar direcciones de canciones
	Musica* cancion; //Auxiliar para llenar el vector de musica
	vector <Musica*> musicFiles;

	Texto textoAux;
public:


	void run();
	void handle_events();
	void updateDirection();
	bool initSDL();
	bool initMedia(); //carga las texturas en el vector de texturas (fuente y música)
	
	void setSalir(){ exit = true; }
	void freeMedia();
	void closeSDL();

	///////Getters
	SDL_Renderer* getRender() const { return pRenderer; }
	SDL_Rect getCamera(){ return camera; }
	Textura* getTextura(Texturas_t et) const { return arrayTex[et]; }
	void getMousePos(int & mpx, int & mpy) const;
	int getHeight() const;
	int getWidth() const;
	int getVelX();
	int getVelY();





};

