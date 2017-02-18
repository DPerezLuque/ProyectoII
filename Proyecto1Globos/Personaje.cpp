#include "Personaje.h"
#include "PlayPG.h"

Personaje::Personaje(juegoPG* pGame)
{
	visible = true;
	pJuego = pGame;					//Le damos el puntero que apunta a la instancia del juego.
	Textura = TPerso;

	//Posición donde se renderizará el globo (pRect heredado)
	pRect.w = 100;
	pRect.h = 170;
	pRect.x = 300;
	pRect.y = 150;

	frameRect = pRect;
}


Personaje::~Personaje()
{
}

bool Personaje::onClick(){
	//PRACTICA2: Aqui llamaremos a el metodo dentro() que hereda de ObjetoPG
	if (dentro(pJuego->getMouseX(), pJuego->getMouseY()) && visible){
		static_cast<PlayPG*> (pJuego->getCurrentState())->newPuntos(this);
		static_cast<PlayPG*> (pJuego->getCurrentState())->newBaja(this);
		return true;
	}
	else
		return false;
}

void Personaje::update(){

	frameRect.x += frameRect.w;

	pRect.x++;

}

