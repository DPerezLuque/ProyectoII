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
private:
	int contParado = 0;
	int contAceleron = 0;
	int posx, posy;
};

