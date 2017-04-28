#pragma once
#include "Objeto.h"
class objetoDecorativo : public Objeto
{
public:
	objetoDecorativo(Juego* ptr, int px, int py, std::string);
	~objetoDecorativo();
	
	void setObjectFromString(std::string);		//Factoría de objetos decorat
	virtual void update(int delta){}			//En principio, no usamos el update pero será útil si el objeto tiene animación
	void onCollision(collision){};				//Por si queremos meter animaciones cuando tocas

};

