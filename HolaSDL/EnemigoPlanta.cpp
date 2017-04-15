#include "EnemigoPlanta.h"


EnemigoPlanta::EnemigoPlanta(Juego* ptr, int px, int py) : enemy(ptr, px, py)
{
	textura = juego->getTextura(Juego::TEnemy); //TODO: cambiar a la textura de la planta
	vidaEnemigo = 5;
}


EnemigoPlanta::~EnemigoPlanta()
{
}

void EnemigoPlanta::update(int delta){
	int x, y;
	static_cast <Play*> (juego->topEstado())->posPlayer(x, y);
	++contDis;
	if (contDis >= freDis){
		shoot(x, y);
		contDis = 0;
	}

	gestorVida(vidaEnemigo);
}
