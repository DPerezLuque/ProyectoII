#include "Premio.h"

Premio::Premio(juegoPG* pGame, int px, int py)
{
	AP = 10;		//Puntos al principio	
	pJuego = pGame;
	visible = false;
	Textura = TPremio;

	//Parametros del pRect (posición inicial)
	pRect.x = px;
	pRect.y = py;
	pRect.w = 88; 
	pRect.h = 98;
	frameRect = pRect;
}

Premio::~Premio()
{
}

void Premio::update(){
}

bool Premio::onClick(){
	if (dentro(pJuego->getMouseX(), pJuego->getMouseY()) && visible){ 
		static_cast<PlayPG*> (pJuego->getCurrentState())->newPuntos(this);
		static_cast<PlayPG*> (pJuego->getCurrentState())->desactivaPremio();
		reiniciarPremio();
		return true;
	} else {
		if (AP < PP) AP += 10;
		return false; 
	}
}

void Premio::reiniciarPremio() {
	//Reiniciamos la puntuación
	AP = 10;
	//Cambiamos la posición
	pRect.x = rand() % 700;	//ancho de la pantalla - 100
	pRect.y = rand() % 500;	//alto de la pantalla - 100
	//Lo ponemos a invisible
	visible = false;
};
