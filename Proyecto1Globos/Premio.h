#pragma once
//#ifndef PREMIO_H
//#define PREMIO_H
#include "ObjetoPG.h"
#include "PlayPG.h"

class Premio:public ObjetoPG
{
public:
	//Atributos publicos
	int PP = 40;	//Puntos m�ximos totales que puede llegar a valer el premio		

	//Metodos publicos
	Premio(juegoPG* pGame, int px, int py);
	~Premio();

	//Propios
	void hacerVisible(){ visible = true; };
	void aumentarAP(){ AP += 10; };
	void reiniciarPremio();
	//Comunes
	//METODOS DEL ENUNCIADO	
	//virtual void draw() const;
	virtual bool onClick();
	virtual void update();
	virtual int getPuntos(){ reiniciarPremio();	return AP; }; //Redefine el m�todo del padre

private:
	
};

//#endif