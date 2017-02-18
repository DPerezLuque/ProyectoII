#pragma once
//#ifndef JUEGO_PG_H
//#define JUEGO_PG_H
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>
#include <stack>
#include "EstadoJuego.h"
#include "ObjetoJuego.h"
#include "TexturasSDL.h"
using namespace std;

//VARIABLES GLOBALES
enum Texturas_t { TFondo, TPerso, TBala, TPremio, TBMenu, TBResume, TBExit, TBPlay, TBScore };		// Practica 2: enumerador de texturas
enum estados_t {EMenu, EGameOver, EPausa, EJuego}; //EstadoJuego tambien lo requiere?

class juegoPG
{
public:
	//ATRIBUTOS PUBLICOS

	//METODOS PUBLICOS
	juegoPG();		//Constructora
	~juegoPG();					//Destructora

	//GESTION DE ESTADOS
	EstadoJuego* getCurrentState() { return pila_estado.top(); } //esto debería ser con 
	void changeState(EstadoJuego* nuevo);
	void pushState(EstadoJuego* newState);
	void popState();
	void setSalir(); //Para MenuPG: Implementar el metodo en .cpp para salir de juego
	bool estadoPlay;
	void MostrarPuntuacion();
	void run();	
	void setPuntos(int nuevaPuntuacion) { points = nuevaPuntuacion; }
	// info
	void cambiaEstadoPlay() { estadoPlay = !estadoPlay; } //para pausa detectar si se esta en play o no al pulsar ESC
	bool getEstadoPlay() { return estadoPlay; }
	int getPuntos() { return points; }		//Para GameOver
	int getMouseX() { return pClickX; }
	int getMouseY() { return pClickY; }
	int getScreenW() { return SCREEN_WIDTH; }
	int getScreenH() { return SCREEN_HEIGHT; }
	SDL_Renderer* getRender() const { return pRenderer; }							//Devuelve el render
	TexturasSDL* getTextura(Texturas_t et) const { return texturas[et]; }			//Devuelve una textura concreta del enumerador
	
private:
	//ATRIBUTOS PRIVADOS
	int SCREEN_WIDTH = 800;					//Ancho de ventana
	int SCREEN_HEIGHT = 600;				//Altura de ventana

	//Estados
	stack<EstadoJuego*> pila_estado;	//Metodos: pop, push, top, empty

	vector<string> nombreTexturas;
	TexturasSDL * texturas[9];				//9 es el numero de texturas
	SDL_Window * pWindow;					//La ventana	//Tambien se usa SDL_Surface * Screen para pantalla ¿Diferencias?
	SDL_Renderer * pRenderer;				//El renderizador de la ventana
	SDL_Rect rectBG;
	int pClickX, pClickY;					//Posiciones del ratón
	
	//Atributos a guardar/cargar en pausa
	int points;
	int punctured;
	bool activePrice;
	vector<ObjetoJuego*> vObjects;
	int ballonQuant;

	//Eventos
	bool error;								//Variable de estado Error
	bool exit;								//Variable de estado exit
	bool gameOver;							//Necesario para run(), ¿O acaso vale con declararlo dentro de run()?

	//Musica* musica;
	

//METODOS PRIVADOS
	//Init
	bool InitSDL();							//Inicializadora del SDL 
	void initMedia();	//Practica2

	//Draw
	void render();

	//Input
	void handle_event();
	void closeSDL();
	void freeMedia();	//Practica2
	bool onExit();
};

//#endif