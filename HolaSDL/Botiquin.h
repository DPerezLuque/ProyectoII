#pragma once
#include "Objeto.h"

class Botiquin : public Objeto
{
public:
	Botiquin(Juego* ptr, int px, int py);
	virtual ~Botiquin();
	void onCollision();
	void update(int delta);
	//Necesita que en el OnCollision se le suba la vida a Player, igual pasandoselo como parametro en la constructora?
};

