#pragma once
#include "Objeto.h"
class ObjetoDecorativo : public Objeto
{
public:
	ObjetoDecorativo(Juego* ptr, int px, int py, std::string);
	~ObjetoDecorativo();
	
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

