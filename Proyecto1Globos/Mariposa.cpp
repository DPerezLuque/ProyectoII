#include "Mariposa.h"

Mariposa::Mariposa(juegoPG* pGame, int px, int py)
{
	AP = 0; //Puntuacion
	pJuego = pGame; //Le damos el puntero de la instancia juego.
	visible = true;

	//Parametros del pRect (posición inicial)
	pRect.x = px;
	pRect.y = py;
	pRect.w = 70;
	pRect.h = 65;

	//Parametros del frameRect
	frameRect.x = 0;
	frameRect.y = 0;
	frameRect.w = 980 / 14;
	frameRect.h = 65;


	//Textura = TMariposa;

	contador = 0;	
}


Mariposa::~Mariposa()
{
}

void Mariposa::draw() const{ //Su draw es distinto por la animación
	(pJuego->getTextura(Textura))->render(pJuego->getRender(), pRect, frameRect);
}

void Mariposa::update(){

	//GESTION DEL FRAME
	//Cambio de frame
	frameRect.x += frameRect.w;
	// Reiniciar al frame 1
	if (frameRect.x < 13 * frameRect.w){
		frameRect.x += frameRect.w;
	}
	else frameRect.x = 0;

	//Cambiar su posicion
	pRect.x += 20;
	if (pRect.x >= pJuego->getScreenW()) pRect.x = 0;	//Si se sale de pantalla aparecer por el otro lado
}

bool Mariposa::aparecePremio(){		//¿Espera que juego llame a este metodo del nieto desde un puntero al abuelo? @_@
	if (contador >= 3){
		contador = 0; //Reinicia el contador
		return true;		
	} else return false; 
}

bool Mariposa::onClick(){
	//PRACTICA2: Aqui llamaremos a el metodo dentro() que hereda de ObjetoPG
	if (dentro(pJuego->getMouseX(), pJuego->getMouseY())){
		//GESTION PREMIO
		contador++;		//aumentamos 1 valor el contador
		static_cast<PlayPG*> (pJuego->getCurrentState())->newPremio(this);

		//GESTION CAMBIO POSICION MARIPOSA
		pRect.x = rand() % 700;	//ancho de la pantalla - 100
		pRect.y = rand() % 500;	//alto de la pantalla - 100

		return true;
	}
	else {
		return false;
	}
}