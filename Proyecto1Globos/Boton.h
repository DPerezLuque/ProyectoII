#pragma once
#include "ObjetoPG.h"
#include "juegoPG.h"

class Boton:public ObjetoPG {
public:
	typedef void Callback_t(juegoPG* pGame);
	Boton(Callback_t * cb, juegoPG* pGame, int posX, int posY, Texturas_t ownText);
	~Boton();
	
protected:
	Callback_t * cbOnClick = nullptr;

private:
	bool onClick();
	void update();
};


