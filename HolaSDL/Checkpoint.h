#pragma once
#include "Objeto.h"
#include "Player.h"

class Checkpoint :	public Objeto
{
public:
	Checkpoint(Juego* ptr, int px, int py, Player* p);
	virtual ~Checkpoint();
	void onCollision();
	void draw() const; //Necesita su propio draw, por la animacion
	void update(int delta);
	void setPosition(int x, int y);

private:
	bool cogido;
	SDL_Rect rectAnim;
	void animar();
	int contador; //Para los frames
	Player* jugador;
};

