#pragma once
#include <vector>
#include <string>
#include <stack>

#include "SDL.h"

#include "Textura.h"
#include "EstadoJuego.h"

#include "Musica.h"
#include "Efecto.h"

#include "Texto.h"

using namespace std;

class Juego
{
public:

	SDL_Renderer* pRenderer;
	SDL_Window* pWindow;
	SDL_Color pcolor;
	Textura * pTexture;
	std::vector<std::string> texturas;
	std::vector<Textura*> arrayTex;

	int const SCREEN_WIDTH = 640;// 860;
	int const SCREEN_HEIGHT = 480;
	int x, y;
	bool exit;
	static const int VPLAYER = 10;
	int mVelX, mVelY;

	SDL_Event e;

	EstadoJuego* estado;
	
	std::stack<EstadoJuego*> states;
///////

	Juego();
	~Juego();

	enum Texturas_t { TPlayer = 0, TBulletPlayer = 1, TBExit = 2, TBPlay = 3, TBMenu = 4, TBResume = 5, TEnemy = 6, TBulletEnemy = 7 };

	void run();

	void handle_events();
	void updateDirection();
	bool initSDL();
	bool initMedia(); //carga las texturas en el vector de texturas (fuente y música)
	
	void setSalir();
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

	///////Pila
	void changeState(EstadoJuego* newSt);
	void pushState(EstadoJuego* newState);
	void popState();
	EstadoJuego* topEstado();

private:
	//Level camera
	SDL_Rect camera;
	//Musica
	enum MusicIds {	Come,};
	vector <string> musicNames;//Vector para almacenar direcciones de canciones
	Musica* cancion; //Auxiliar para llenar el vector de musica
	vector <Musica*> musicFiles;

	////
	Efecto* effectFile;

	Texto textoDePrueba;
	Textura* cosaDePrueba;
	SDL_Color Black;
	SDL_Rect rectamgulon;
	

};

