#pragma once
#include "enemy.h"
class EnemigoPlanta : public enemy
{
public:
	EnemigoPlanta(Juego* ptr, int px, int py);
	~EnemigoPlanta();

	void draw() const;
	void update(int delta);
	void animacionBasica();
	void onCollision();
	void gestorVida(int &vida);
private:
	SDL_Rect rectAnim;
	int contador; //Para el paso de frames
};

