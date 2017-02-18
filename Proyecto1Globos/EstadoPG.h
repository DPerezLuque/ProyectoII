#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>
#include "EstadoJuego.h"
#include "juegoPG.h"
#include "ObjetoJuego.h"
#include "Boton.h"

class EstadoPG : public EstadoJuego {
public: 
	//Metodos publicos
	EstadoPG();
	~EstadoPG();
	juegoPG* pJuego;
	vector<ObjetoJuego*> vObjetos;

protected:
	void draw() const;
	void onClick();
	void update(){}; //En principio los objetos de los estados no se actualizan (botones) excepto PlayPG, que ya lo implementa.
	void freeObjects();

private: 

};

