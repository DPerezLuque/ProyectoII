#pragma once
#include "Objeto.h"
class EnemigoBase : public Objeto
{
public:
	EnemigoBase(Juego* ptr, int px, int py);

	virtual ~EnemigoBase();

	//	Métodos virtuales de objeto que usan todos los enemigos	//
	virtual void onCollision(collision type);
	virtual void draw() const;
	virtual void shoot(int targetX, int targetY, char bulletType);		//bulletType: 'n' -> Bala enemiga    'b' -> Bala explosiva

	virtual void follow(int x, int y, float delta);
	virtual void gestorVida();
	virtual bool isActive();
	virtual void animacionBasica()= 0;
	// 

protected:
	Efecto* sonidoMuerte;

	bool dropLlave = false;
	int vX, vY;				//Velocidades para el método follow
	int vel;				//velocidad del monimiento
	int contDis = 0;		//Contador que regula la cadencia
	int freDis;				//frecuencia con la que dispara
	int velDis;				//velocidad del disparo

	bool doorCollision;
	//bool inmunidad;			//Booleano que se activa cuando toca un enemigo para que no reste la vida de golpe
	int contInm;			//Contador inmunidad

	int radioEnable;		//Valor de activacion del area de disparo
	int radioDisable;		//Valor de desactivacion del area de disparo
	bool active;			//Bool que determina si la unidad dispara o no
	bool spawnAura = true;	//Bool que determina si la unidad suelta o no un alma

	Textura* barraVida;		//Textura de la barra superior de cada unidad
	SDL_Rect rectVida;		//Rectangulo que representa la textura

	//SDL_Rect rectAnim;		//Rectangulo para la animación, si hubiera
	//int contadorFrames;		//Para el paso de frames de la animación

};

