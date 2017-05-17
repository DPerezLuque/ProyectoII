#pragma once
#include "enemigoBase.h"
class BossRino : public enemigoBase
{
public:
	BossRino(Juego* ptr, int px, int py);
	~BossRino();
	void carga(float x, float y);
	void update(int delta);
	enum Estados { NORMAL, PARADO, CARGA, SHOOT, ESTUNEADO };
	Estados estado = NORMAL;
	virtual void onCollision(collision type);
	virtual void animacionBasica() {}
	virtual void follow(int x, int y, float delta);
private:
	int contParado = 0;
	int contStun = 0;
	int posx, posy;
	float distance;
	float saveTargetX, saveTargetY;
	bool saved;
	int atack;
};
