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
	
	void draw() const;	

	void onCollision();

private:
	int velX, velY;
	SDL_Rect rectAnim;
	enum animacion {derecha, izquierda, arriba, abajo, dchaUp, dchaDown, izdaUp, izdaDown };
	void animar(animacion current);
	void animacionBasica(); //Para el paso de frames
	void proceso();
	int contador; //Para los frames
};

