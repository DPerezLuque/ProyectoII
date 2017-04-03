#include "EnergiaDisponible.h"


EnergiaDisponible::EnergiaDisponible(Juego* pJuego, SDL_Rect Camera, int ancho, int alto) : Interfaz(pJuego, Camera, ancho, alto)
{
	//Misma constructora que interfaz
	distX = 30;
	distY = 60;

	numEnergias.push_back(pRect); //El primer rectangulo es el normal
}


EnergiaDisponible::~EnergiaDisponible()
{
}

void EnergiaDisponible::update(SDL_Rect Camera, int contador){

	//Hay que actualizar todos los rectangulos respecto la camara, el draw les da distancia entre ellas.
	for (int i = 0; i < numEnergias.size(); i++) {
		numEnergias[i].x = Camera.x + distX;
		numEnergias[i].y = Camera.y + distY;
	}

	if (contador > cuenta){ //Cuenta interna del numero de energias
		numEnergias.resize(contador);//Aumenta de uno en uno, no hay problema,
		numEnergias.push_back(pRect); //La siguiente posicion del vector será un rectángulo igual (mismas dimensiones)
		//El draw se encargará de separarlos entre si
		cuenta = contador; //Para no volver a entrar hasta que aumente
	}
	
}

void EnergiaDisponible::draw(){
	for (int i = 0; i < numEnergias.size(); i++) {		
		textura->draw(pRenderer, numEnergias[i]);
		numEnergias[i].x += 50; //50 pixeles de diferencia entre ellas
	}
}
