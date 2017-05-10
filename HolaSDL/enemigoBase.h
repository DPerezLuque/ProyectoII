#pragma once
#include "Objeto.h"
class enemigoBase : public Objeto
{
public:
	enemigoBase(Juego* ptr, int px, int py);
	~enemigoBase();

	//	Métodos virtuales de objeto que usan todos los enemigos	//
	virtual void onCollision(collision);
	virtual void draw() const;
	virtual void shoot(int targetX, int targetY);
	virtual void follow(int x, int y, float delta);
	virtual void gestorVida();
	virtual bool isActive();
	virtual void animacionBasica()= 0;
	// 


protected:
	int vX, vY;				//Velocidades para el método follow
	int vel;				//velocidad del monimiento
	int contDis = 0;		//Contador que regula la cadencia
	int freDis;				//frecuencia con la que dispara
	int velDis;				//velocidad del disparo

	bool inmunidad;			//Booleano que se activa cuando toca un enemigo para que no reste la vida de golpe
	int contInm;			//Contador inmunidad

	int radioEnable;		//Valor de activacion del area de disparo
	int radioDisable;		//Valor de desactivacion del area de disparo
	bool active;			//Bool que determina si la unidad dispara o no
	bool animado;			//Bool que determina si el objeto tiene animación o no

	Textura* barraVida;		//Textura de la barra superior de cada unidad
	SDL_Rect rectVida;		//Rectangulo que representa la textura

	SDL_Rect rectAnim;		//Rectangulo para la animación, si hubiera
	int contadorFrames;		//Para el paso de frames de la animación

};

