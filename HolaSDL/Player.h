#pragma once
#include "Objeto.h"


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

	void onCollision(ObjetoJuego * colisionado);

	int getVida(){ return vida; }
	int getBalas(){ return balas; }

	void gestorVida(int &vida);


private:
	int velX, velY;
	int vida;
	int balas;

	bool inmunidad; //Booleano que se activa cuando toca un enemigo para que no reste la vida de golpe
	int contadorInmunidad; //Contador del tiempo de inmunidad

};

