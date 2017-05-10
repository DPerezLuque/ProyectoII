#pragma once
#include "Interfaz.h"
#include "SDL.h"
#include <vector>

class EnergiaDisponible :
	public Interfaz
{
public:
	EnergiaDisponible(Juego* pJuego, ObjetoJuego* jugador, int ancho, int alto, int posX, int posY);
	virtual ~EnergiaDisponible();
	void update();
	void draw() const; //Cambiamos el draw, recorrerá el vector de rectangulos y dibujará todos

	Textura* textura2; //DashVacio	
private:
	bool activo;
	SDL_Rect rectAnim;
};

