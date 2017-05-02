#pragma once
#include "Objeto.h"
class objetoDecorativo : public Objeto
{
public:
	objetoDecorativo(Juego* ptr, int px, int py, std::string);
	~objetoDecorativo();
	
	void setObjectFromString(std::string);		//Factoría de objetos decorat
	void draw() const;
	void update(int delta);
private:
	void animacionBasica();
	SDL_Rect rectAnim;
	string tipo = "e"; //estatico y animado
	string tipoAnim;
	int contador = 0; //Paso de frames

};

