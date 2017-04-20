#pragma once
#include "Objeto.h"
#include "Player.h"
class Checkpoint :	public Objeto
{
public:
	Checkpoint(Juego* ptr, int px, int py);
	virtual ~Checkpoint();
	void onCollision(ObjetoJuego * colisionado);
	void draw() const; //Necesita su propio draw, por la animacion
	void update(int delta);

private:
	bool cogido;
	SDL_Rect rectAnim;
	void animar();
	void setPosition(Player* p, int x, int y);
	int contador; //Para los frames
};

