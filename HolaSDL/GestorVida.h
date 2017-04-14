#pragma once

#include "Juego.h"

class GestorVida
{
public:
	GestorVida(Juego* juego);
	~GestorVida();


	static void muerteYDestruccion();

private:
	
	Juego* game;


};
