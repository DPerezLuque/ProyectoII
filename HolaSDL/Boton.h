#pragma once
#include "Objeto.h"

class Boton : public Objeto
{
public:
	
	typedef void CallBack_t(Juego* jg);
	Boton(Juego* ptr, int px, int py, Juego::Texturas_t tex, collision type);
	virtual ~Boton();

//	void update(int delta) {};

private:
	//CallBack_t * cbOnClick;
};

