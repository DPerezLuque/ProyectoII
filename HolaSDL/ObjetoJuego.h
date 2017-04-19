#pragma once
#include <SDL.h>

//Collision Manager
enum collision { PJ = 1, ENEMY = 2, WEAPON = 3, ENVIROMENT = 4, CHECK = 5 };

class ObjetoJuego
{
public:

	virtual ~ObjetoJuego() {}

	virtual void draw() const = 0;

	virtual void update(int delta) = 0;

	virtual bool onClick() = 0;
	
	virtual SDL_Rect getRect() = 0;

	virtual void onCollision(ObjetoJuego * colisionado) = 0;

	virtual bool isDead() = 0;

	virtual collision getType() = 0;
};

