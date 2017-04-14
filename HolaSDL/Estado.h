#pragma once
#include "EstadoJuego.h"
#include "Juego.h"


class Estado : public EstadoJuego
{
public:

	Estado(Juego* ptr);
	virtual ~Estado();

	void draw();
	void update(int delta);
	void onClick();

	vector<ObjetoJuego*> getArray() const { return arrayObjetos; }; //Getter del array de objetos

	vector<ObjetoJuego*> arrayObjetos;
protected:

	Juego* juego;
	SDL_Renderer* pRenderer;
	Textura* textura;


	int height, width;
};

