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
	void drawPlayer();
	void onCollision();

private:
	int velX, velY;
};

