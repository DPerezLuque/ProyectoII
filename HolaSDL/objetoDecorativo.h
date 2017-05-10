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
	bool animado;		 //determina si el objeto está o no animado
	string tipoAnim;
	int contador = 0;	 //Paso de frames

};

