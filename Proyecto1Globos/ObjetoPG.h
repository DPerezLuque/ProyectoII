#pragma once
#include "ObjetoJuego.h"
#include "juegoPG.h"

class ObjetoPG : public ObjetoJuego {
public:
	//METODOS PUBLICOS
	ObjetoPG();
	~ObjetoPG();
	
	Texturas_t Textura;
	juegoPG* pJuego;
	bool dentro(int x, int y) const;	//Puede implementar parte de los métodos que hereda
	virtual void draw() const;
	virtual int getPuntos(){ return AP; };				//Cada objeto obtendrá puntos de manera diferente

protected:	//rectangulos comunes a todos los objetos 
	SDL_Rect pRect, frameRect;
	bool visible;
	int AP;
	
private: 
	
};
