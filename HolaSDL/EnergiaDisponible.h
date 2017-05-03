#pragma once
#include "Interfaz.h"
#include "SDL.h"
#include <vector>

class EnergiaDisponible :
	public Interfaz
{
public:
	EnergiaDisponible(Juego* pJuego, SDL_Rect Camera, int alto, int ancho, int posX, int posY);
	virtual ~EnergiaDisponible();
	void update(SDL_Rect Camera, int contador);
	void draw() const; //Cambiamos el draw, recorrerá el vector de rectangulos y dibujará todos

	int cuenta = 1; //Numero inicial de energia
	Textura* textura2; //DashVacio	
private:
	bool activo;
};

