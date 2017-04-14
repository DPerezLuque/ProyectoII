#pragma once
#include "enemy.h"
class BossRino: public enemy
{
public:
	BossRino(Juego* ptr, int px, int py);
	~BossRino();
	void carga(float x, float y);	
	void update(int delta);
	enum Estados{NORMAL, PARADO, CARGA, ESTUNEADO};
	Estados estado = NORMAL;
	void onCollision(collision c);
private:
	int contParado = 0;
	int contStun = 0;
	int posx, posy;
	float distance;
	float saveTargetX, saveTargetY;
	bool saved;
};

