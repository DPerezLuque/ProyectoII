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
	void getPos(int& x, int& y);

	void setCamera(SDL_Rect &camera);
	//void drawPlayer();
	void draw() const;
	void onCollision() {};
	void onCollision(ObjetoJuego*);

	int getVida(){ return vida; }
	int getBalas(){ return balas; }

	int posIniX, posIniY;
	void gestorVida(int &vida);

private:
	void respawn();
	int velX, velY;

	int vida;
	int balas;

	bool inmunidad; //Booleano que se activa cuando toca un enemigo para que no reste la vida de golpe
	int contadorInmunidad; //Contador del tiempo de inmunidad

	//ANIMACIÓN PERSONAJE
	SDL_Rect rectAnim;
	enum animacion {derecha, izquierda, arriba, abajo, dchaUp, dchaDown, izdaUp, izdaDown };
	void animar(animacion current);
	void animacionBasica(); //Para el paso de frames
	void proceso();
	int contador; //Para los frames
	int contador2; //Para recargar arma
	int maximoBalas;
};

