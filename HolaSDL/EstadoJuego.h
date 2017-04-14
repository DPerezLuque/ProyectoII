#pragma once

#include "ObjetoJuego.h"
#include "SDL.h"
#include <vector>

using namespace std;

class EstadoJuego
{
public:

	EstadoJuego() {}
	virtual ~EstadoJuego(){}

	virtual void draw() = 0;

	virtual void update(int delta) = 0;

	virtual void onClick() = 0;

	virtual vector<ObjetoJuego*> getArray() const = 0;
};

