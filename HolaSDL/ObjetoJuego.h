#pragma once
#include <SDL.h>

//Collision Manager
enum collision {
	PJ = 1, ENEMY = 2, WEAPON = 3, ENVIROMENT = 4, CHECK = 5, BOSS = 6,
	PJ_WEAPON = 7, ENEMY_WEAPON = 8, AURA = 9, BOTIQUIN = 10, DECORATIVO = 11, BOTON_PLAY = 12,
	BOTON_EXIT = 13, BOTON_MENU = 14, BOTON_RESUME = 15, BOTON_CONTROLS = 16, BOTON_OPTIONS = 17,
	EXPLOSION = 18, SIN_TIPO = 19, BOTON_SANGRE = 20, BOTON_FILTER = 21, BALA_RALENTIZADORA = 22
};



class ObjetoJuego
{
public:

	virtual ~ObjetoJuego() {}

	virtual void draw() const = 0;

	virtual void update() = 0;

	virtual void update(int delta) = 0;

	virtual bool onClick() = 0;

	virtual bool dentro(int x, int y) const = 0;
	
	virtual SDL_Rect getRect() = 0;

	virtual void getPos(int& x, int& y) = 0;

	virtual void gestorVida() = 0;

	virtual void onCollision() = 0;

	virtual void onCollision(collision type) = 0;

	virtual bool isDead() = 0;

	virtual collision getType() = 0;

	virtual bool isInside() = 0;

	virtual void putInside() = 0;

	virtual void getStats(int &life, int &bullets, int &dash) = 0;

	virtual void changeText() = 0;

	virtual int getVida() = 0;
};

