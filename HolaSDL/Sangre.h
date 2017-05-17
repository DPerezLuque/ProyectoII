#pragma once
#include "Objeto.h"
class Sangre :
	public Objeto
{
public:
	Sangre(Juego* ptr, int px, int py);
	~Sangre();

	void onCollision(collision type){}
	void update(int delta);
	void draw() const;

};

