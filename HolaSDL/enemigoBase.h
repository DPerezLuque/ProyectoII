#pragma once
#include "Objeto.h"
class enemigoBase : public Objeto
{
public:
	enemigoBase(Juego* ptr, int px, int py);
	~enemigoBase();

	//	Métodos virtuales de objeto que usan todos los enemigos	//
	virtual void onCollision(collision);
	virtual void draw() const;
	virtual void shoot(int targetX, int targetY);
	virtual void follow(int x, int y, float delta) = 0;
	virtual void gestorVida();
	// 



};

