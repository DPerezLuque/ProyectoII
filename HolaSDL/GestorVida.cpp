#include "GestorVida.h"



GestorVida::GestorVida(Juego* juego)
{
	game = juego;
}


GestorVida::~GestorVida()
{
}

void GestorVida::muerteYDestruccion() 
{
	/* Cada uno revisado con un if o switch para saber qu� es el objeto que ha muerto (vidaObj = 0)
	Play:: restaEnemigo //Enemigo muerto
	Play:: restaBala //Eliminar balas, puede que algunas sean perforantes y tengan m�s de una vida -> En principio no
	Play:: gameOver //Player muerto
	*/
}
