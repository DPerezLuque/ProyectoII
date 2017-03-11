#pragma once
#include "EstadoJuego.h"
#include "ObjetoJuego.h"
#include "Juego.h"


class Estado : public EstadoJuego
{
public:

	Estado(Juego* ptr);
	virtual ~Estado();

	void draw();
	void update();
	void onClick();

protected:

	Juego* juego;
	SDL_Renderer* pRenderer;
	Textura* textura;

	std::vector<ObjetoJuego*> arrayObjetos;

	int height, width;
};

