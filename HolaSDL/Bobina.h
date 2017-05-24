#pragma once
#include "Objeto.h"
class Bobina : public Objeto
{
public:
	Bobina(Juego* ptr, int px, int py);
	virtual ~Bobina();
	void onCollision(collision type);
	void draw() const; //Necesita su propio draw, por la animacion
	void update(int delta);
private:
	Textura* textura2;
	SDL_Rect rectAnim;
	void animar();
	int contador; //Para los frames
};

