#include "Botiquin.h"


Botiquin::Botiquin(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TBotiquin);
	rect.w = 64;
	rect.h = 64;
	rectCollision = rect;

	tipo = BOTIQUIN;
}


Botiquin::~Botiquin()
{
}

void Botiquin::update(int delta){
	Oscilar(delta);
}

void Botiquin::onCollision(collision noSeUsa){
	//Aqui falta que se quite, la vida la sube el jugador
	dead = true;
}