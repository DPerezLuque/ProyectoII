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

	ObjetoJuego* getObjeto(int i) const { return arrayObjetos[i]; }; //Getter del objeto i del array
	int getSizeArray() const { return arrayObjetos.size(); }; //Getter del tamaño del array

	vector<ObjetoJuego*> arrayObjetos;
protected:

	Juego* juego;
	SDL_Renderer* pRenderer;
	Textura* textura;


	int height, width;
};

