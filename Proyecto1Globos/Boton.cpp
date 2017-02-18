#include "Boton.h"

Boton::Boton(Callback_t * cb, juegoPG* pGame, int posX, int posY, Texturas_t ownText){
	pRect.x = posX;
	pRect.y = posY;
	pRect.w = 250;
	pRect.h = 50;
	Textura = ownText;
	cbOnClick = cb;
	visible = true;
	pJuego = pGame;
}

bool Boton::onClick(){
	if (dentro(pJuego->getMouseX(), pJuego->getMouseY())){
		cout << "Boton pulsado\n";
		cbOnClick(pJuego);
		return true;
	}
	else
		return false;
}

void Boton::update(){
}

Boton::~Boton()
{ 
}
