#include "GlobosPG.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

using namespace std;

GlobosPG::GlobosPG(juegoPG* pGame, int px, int py)		//Este es el constructor de globos que se llamará para crear un nuevo globo en el vector, se definen las caracteristicas de este.
{
	AP = 1;							//Puntos que da el globo en el estado actual
	DT = 4;							//Estado de desinflado del globo						(DUDA = ¿Innecesario si utilizo el globRect.x?)	
	visible = false;
	pinchado = false;				//Si ha sido explotado o desinflado
	pJuego = pGame;					//Le damos el puntero que apunta a la instancia del juego.
	//Textura = TGlobo;


	//Posición donde se renderizará el globo (pRect heredado)
	pRect.x = px;
	pRect.y = py;	
	pRect.w = 128;
	pRect.h = 128;
	frameRect = pRect;	//frameRect heredado.
}


GlobosPG::~GlobosPG()
{
}

bool GlobosPG::onClick(){
	//PRACTICA2: Aqui llamaremos a el metodo dentro() que hereda de ObjetoPG
	if (dentro(pJuego->getMouseX(), pJuego->getMouseY()) && visible){
		static_cast<PlayPG*> (pJuego->getCurrentState())->newPuntos(this);
		static_cast<PlayPG*> (pJuego->getCurrentState())->newBaja(this);
		return true;
	} else
		return false;
}

void GlobosPG::update(){

	if (!pinchado){
		//Probabilidad de que se vea este ciclo
		if (rand() % 100 < PVIS){ 
			visible = true;
		} else { visible = false; }			//Si el globo se ve o no en cada ciclo

		//Probabilidad de que se desinfle
		if (rand() % 100 < PDES) { pRect.w -= 8; pRect.h -= 8; DT -= 0.25; AP += 2; } //tras 16 ciclos activado el random se reduce todo a 0

		//Si alcanza el punto en el que no se ve el globo
		if (pRect.w <= 10 || pRect.h <= 10) { 
			cout << "El globo se ha desinflado";

			static_cast<PlayPG*> (pJuego->getCurrentState())->newBaja(this);
		}	//Si se desinfla hacemos que "desaparezca"
	}

}
