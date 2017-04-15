#pragma once
#include "EstadoJuego.h"
#include "ObjetoJuego.h"
#include "Juego.h"
#include "HUD.h"
using namespace std;

class Estado : public EstadoJuego
{
public:

	Estado(Juego* ptr);
	virtual ~Estado();

	void draw();
	void update(int delta);
	void onClick();

	std::vector<ObjetoJuego*> arrayObjetos;
protected:

	Juego* juego;
	SDL_Renderer* pRenderer;
	Textura* textura;
	
	vector <HUD*> elemInterfaz; //Estarán todos los elementos de la interfaz
	SDL_Rect camera_; //Utilizado por interfaz
	
	std::vector<int> stats;

	int height, width;
};

