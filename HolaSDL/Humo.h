#pragma once
#include "Objeto.h"
class Humo :public Objeto
{
public:
	Humo(Juego* ptr, int px, int py);
	~Humo();

	void onCollision(){}
	void update(int delta);
	void draw() const;
private:
	SDL_Rect rectAnim;
	void animacionBasica();
	int contador; //Paso de frames

};

