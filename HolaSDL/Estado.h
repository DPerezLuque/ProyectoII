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
	void update(double delta) {};
	void update();
	bool onClick();
	
	//STATE CHANGER
	void play();
	void menu();
	void options();
	void controls();
	void salir();

	GAME_STATES getCurrentState() { return type; };
	bool isActive() { return active; };
	void setActive(bool act) { active = act; };
	void changeCurrentState(GAME_STATES newType) { type = newType; };
	ObjetoJuego* getObjeto(int i) const { return juego->arrayObjetos[i]; }; //Getter del objeto i del array
	int getSizeArray() const { return juego->arrayObjetos.size(); }; //Getter del tamaño del array

protected:

	Juego* juego;
	SDL_Event e;

	SDL_Renderer* pRenderer;
	Textura* textura;
	
	void resetCamera();
	
	GAME_STATES type;
	bool active;
	int mouse_x, mouse_y;
	int height, width;
};

