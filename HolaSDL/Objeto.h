#pragma once
#include "ObjetoJuego.h"
#include "SDL.h"
#include "Play.h"

class Objeto : public ObjetoJuego
{
public:
	Objeto(Juego* ptr, int px, int py);
	virtual ~Objeto();

	bool dentro(int x, int y) const; //(A LO MEJOR ES NECESARIO)
	void draw() const;
	bool onClick();
	SDL_Rect getRect();

	void gestorVida() {};
	void onCollision(collision) {};

	//Métodos del vector de cols de cada objeto
	virtual void actualizaVectCols() {};
	virtual void añadeAlVectCols(ObjetoJuego*) {};
	//

	collision getType() {
		return tipo;
	}

	bool isDead() {
		return dead;
	}

	void Oscilar(int delta);

protected:
	Juego* juego;
	Textura* textura;
	SDL_Renderer* pRenderer;

	SDL_Rect rect;							//Cuadrado en el que se va a dibujar el objeto
	SDL_Rect rectCollision;

	collision tipo;
	bool dead = false;
	bool inmunidad;
	bool puedeMoverse;						//Bool que siempre estará activo, a no ser que colisione con un Objeto decorativo, en cuyo caso cambiará la dirección
	int velX, velY;							//Velocidad del objeto
	//int h, w; // tamaño (ya va en el rect)
	int vida;
	//Para oscilar
	int cont;
	int cont2;
	bool arriba = true;

	std::vector <ObjetoJuego*> vectColsPropiasObjeto;	//Vector con todos los objetos con los que el objeto que lo porta PUEDE colisionar
														
	//Cada objeto tiene una instancia de este vector, pero no necesariamente dos instancias tienen que ser iguales.
	//No todos los objetos van a usar este vector, pero es para automatizar un poco.

	//Vector de punteros a punteros: std::vector <ObjetoJuego*> * vectColsPropiasObjeto;
	//Igual si llamo a las constructoras en play en vez de en los objetos arreglo el problema del null
};

