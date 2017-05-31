#include "BalaRalentizadora.h"


BalaRalentizadora::BalaRalentizadora(Juego* ptr, int px, int py, int vX, int vY) : Bala(ptr, px, py, vX, vY)
{
	textura = juego->getTextura(Juego::TBalaRalentizadora);

	tipo = ENEMY_WEAPON;

	//balaAnimada = true;
	balaAnimada = false;

	tipo = BALA_RALENTIZADORA;
	//rectAnim = { 0, 0, 42, 35 };

}


BalaRalentizadora::~BalaRalentizadora()
{
}
