#pragma once
#include "EstadoJuego.h"
#include "ObjetoJuego.h"
#include "Juego.h"


class Estado : public EstadoJuego
{
public:

	Estado(Juego* ptr);
	virtual ~Estado();

	virtual void draw();
	virtual void update();
	virtual void onClick();
	virtual void handleEvent(SDL_Event e);

	void getMousePos(int & mpx, int & mpy) const;

protected:

	Juego* juego;
	SDL_Renderer* pRenderer;
	Textura* textura;

	std::vector<ObjetoJuego*> arrayObjetos;

	int height, width, mouseX, mouseY;
};

