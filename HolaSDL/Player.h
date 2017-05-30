#pragma once
#include "Objeto.h"
#include "BalaPlayer.h"



class Player : public Objeto 
{
	
public:
	Player(Juego* ptr, int px, int py);
	~Player();

	void update(int delta);
	bool onClick();

	void setCamera(SDL_Rect &camera);
	//void drawPlayer();
	void draw() const;
	void onCollision(collision type);	
	
	void getStats(int &life, int &bullets, int &dash);
	int getVida(){ return vida; }
	int getBalas(){ return balas; }
	int getDash(){
		if (juego->getDASH()){
			return 0; 
		}
		else{ return 1; }
	}

	int posIniX, posIniY;
	void gestorVida();

	//Control cinematica
	void changeControlCinematica(bool state){
		controlCinematica = state;
	}

private:
	int velX, velY;
	Efecto* aliento;

	int vida;
	int balas;
	int maximoBalas;	

	bool inmunidad;					//Booleano que se activa cuando toca un enemigo para que no reste la vida de golpe
	bool colisionDecorativo;		//Bool que se activa para que el jugador no avance si va a chocar con un objeto DECORATIVO

	int contadorInmunidad;			//Contador del tiempo de inmunidad
	const int inmunidadMAX = 80;	//Tiempo máximo de inmunidad

	bool estaRalentizado;			//Bool para reducir la velocidad del jugador


	//ANIMACIÓN PERSONAJE
	//SDL_Rect rectAnim;
	enum animacion {derecha, izquierda, arriba, abajo, dchaUp, dchaDown, izdaUp, izdaDown };
	void animar(animacion current);
	void animacionBasica(); //Para el paso de frames
	void proceso();
	int contadorFrames;				//Para los frames
	int contadorRecarga;			//Para recargar arma
	int contDashing;				//Para el dash
	int contadorRalentizado;		//Para revertir el estado del bool estaRalentizado

	//Controlar cadencia de disparo
	int conta = 0;
	bool disparo = false;

	/// Control del jugador en la cinemáfica ///
	bool controlCinematica = false;


};

