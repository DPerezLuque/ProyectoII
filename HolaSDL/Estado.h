#pragma once
#include "EstadoJuego.h"
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

	ObjetoJuego* getObjeto(int i) const { return arrayObjetos[i]; }; //Getter del objeto i del array
	int getSizeArray() const { return arrayObjetos.size(); }; //Getter del tamaño del array

protected:

	Juego* juego;
	SDL_Renderer* pRenderer;
	Textura* textura;
	
	vector <HUD*> elemInterfaz; //Estarán todos los elementos de la interfaz
	SDL_Rect camera_; //Utilizado por interfaz
	
	std::vector<int> stats;
	std::vector<ObjetoJuego*> arrayObjetos;

	int height, width;
};

