#pragma once
#include <vector>
#include <string>
#include <stack>

#include "SDL.h"
#include "Textura.h"
#include "EstadoJuego.h"




class Juego
{
private:

	//// PUNTEROS NECESARIOS

	SDL_Renderer* pRenderer;
	SDL_Window* pWindow;
	SDL_Color pcolor;
	Textura * pTexture;
	std::vector<std::string> texturas;
	std::vector<Textura*> arrayTex;

	int const SCREEN_WIDTH = 860;
	int const SCREEN_HEIGHT = 480;
	int x, y;
	bool exit;
	int VPLAYER = 10;
	int mVelX, mVelY;
	//TRUE = SE PUEDE HACER; FALSE = DASH NO DISPONIBLE
	bool dashDisponible = true;
	//Dash
	//bool hazDash;
	int dashX, dashY;

	SDL_Event e, newE;

	
	EstadoJuego* estado;
	std::stack<EstadoJuego*> states;



public:

	Juego();
	~Juego();

	enum Texturas_t { TPlayer = 0, TBulletPlayer =  1, TBExit = 2, TBPlay = 3, TBMenu = 4, TBResume = 5 };

	void run();

	void handle_events();
	void updateDirection();
	bool compruebaDash();
	void initSDL();
	void initMedia(); //carga las texturas en el vector de texturas (fuente y música)
	
	void setSalir();
	void freeMedia();
	void closeSDL();

	///////Getters
	SDL_Renderer* getRender() const { return pRenderer; }
	Textura* getTextura(Texturas_t et) const { return arrayTex[et]; }
	void getMousePos(int & mpx, int & mpy) const;
	int getHeight() const;
	int getWidth() const;
	int getVelX();
	int getVelY();
	void setEvent();
	SDL_Event getEvent() const { return newE; }

	///////Pila
	void changeState(EstadoJuego* newSt);
	void pushState(EstadoJuego* newState);
	void popState();
	EstadoJuego* topEstado();


};

