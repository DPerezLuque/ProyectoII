#pragma once
#include "EnemigoBase.h"
class BossRino : public EnemigoBase
{
public:
	BossRino(Juego* ptr, int px, int py);
	~BossRino();
	void carga(float x, float y, int delta);
	void update(int delta);
	enum Estados { NORMAL, PARADO, CARGA, SHOOT, ESTUNEADO };
	Estados estado = NORMAL;
	virtual void onCollision(collision type);
	virtual void animacionBasica();
	virtual void follow(int x, int y, float delta);
private:
	int contParado = 0;
	int contStun = 0;
	int posx, posy;
	float distance;
	float saveTargetX, saveTargetY;
	bool saved;
	int atack;

	enum animacion { ABAJO, ARRIBA, DERECHA, IZQUIERDA, QUIETO }; //Nos dice qué animación tiene que hacer
	animacion est;
	void animar(animacion current);

};
