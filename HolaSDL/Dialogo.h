#pragma once
#include "Objeto.h"
#include "Texto.h"

class Dialogo : public Objeto
{
public:
	Dialogo(Juego* ptr, int px, int py, int ancho, int alto, std::string texto);
	~Dialogo();
	void draw() const;
	void onCollision(collision){}
	void update(int delta){}
private:
	Texto* escrito;
	Textura* cuadro;
	Textura* mensaje;
	SDL_Color White;
	//Tenemos otra textura "textura"
};

