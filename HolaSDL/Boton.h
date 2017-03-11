#pragma once
#include "Objeto.h"

class Boton : public Objeto
{
public:
	
	typedef void CallBack_t(Juego* jg);
	Boton(Juego* ptr, int px, int py, CallBack_t * cb, Juego::Texturas_t tex);
	virtual ~Boton();

	bool onClick();
	void update();

private:
	CallBack_t * cbOnClick;
};

