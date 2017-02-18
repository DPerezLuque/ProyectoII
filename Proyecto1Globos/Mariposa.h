#pragma once
//#ifndef MARIPOSA_H
//#define MARIPOSA_H
#include "ObjetoPG.h"
#include "PlayPG.h"

class Mariposa:public ObjetoPG
{
public:
	//Atributos
	Mariposa(juegoPG* pGame, int px, int py);
	~Mariposa();

	//METODOS COMUNES
	//METODOS DEL ENUNCIADO	
	virtual void draw() const;
	virtual void update();				//Generico: llamar a Draw aunque generalmente se usara el propio del hijos
	virtual bool onClick();
	
	//virtual int getPuntos(){ return AP; };

	//METODO PROPIO
	bool aparecePremio();				//Este método será llamado desde juego para que ponga el visible de Premio a true o false

private:
	//ATRIBUTOS PRIVADOS
	int contador;		//Para contar los 3 toques que recibe antes de aparecer el premio
};


//#endif