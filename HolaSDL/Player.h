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

	void onCollision() {};
	void onCollision(ObjetoJuego * colisionado);

	int getVida(){ return vida; }
	int getBalas(){ return balas; }

	void onCollision(int vida, collision tipo); //onCollision mergeado de gestor de vida
	void gestorVida(int vida);

	
	void draw() const;	


private:
	int velX, velY;

	int vida;
	int balas;

	bool inmunidad; //Booleano que se activa cuando toc a un enemigo para que no reste la vida de golpe
	int contadorInmunidad; //Contador del tiempo de inmunidad

	//ANIMACIÓN PERSONAJE
	SDL_Rect rectAnim;
	enum animacion {derecha, izquierda, arriba, abajo, dchaUp, dchaDown, izdaUp, izdaDown };
	void animar(animacion current);
	void animacionBasica(); //Para el paso de frames
	void proceso();
	int contador; //Para los frames
};

