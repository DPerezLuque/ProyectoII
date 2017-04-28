#pragma once
#include "Objeto.h"
#include "Player.h"

class Checkpoint :	public Objeto
{
public:
	Checkpoint(Juego* ptr, int px, int py);
	virtual ~Checkpoint();
	void onCollision(collision);
	void draw() const; //Necesita su propio draw, por la animacion
	void update(int delta);
	bool getCogido(){ return cogido; }		//Devuelve ek estado el bool "cogido"	
private:	
	bool cogido;
	SDL_Rect rectAnim;
	void animar();
	int contador; //Para los frames
};

