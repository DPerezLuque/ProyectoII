#pragma once
#include "enemy.h"

class BossRino: public enemy
{
public:
	BossRino(Juego* ptr, int px, int py);
	~BossRino();
	void follow(int x, int y);
	void follow2(int x, int y);
	void update(int delta);
	enum Estaditos{PARADO,ACELERON,NORMAL};
	Estaditos humuluhumulu = Estaditos::NORMAL;
	void sma();
	void onCollision(collision){};					//Aquí se regula que si ha colisionado con las mierdas de barriles, le quite vida
													//ENVIROMENT =/= DECORATIVOS

private:
	int contParado = 0;
	int contAceleron = 0;
	int posx, posy;
};

