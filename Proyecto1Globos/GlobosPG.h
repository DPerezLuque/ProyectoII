#pragma once
//#ifndef GLOBOS_PG_H
//#define GLOBOS_PG_H
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>
#include "ObjetoPG.h"
#include "PlayPG.h"
using namespace std;


class GlobosPG: public ObjetoPG	//HERENCIA de ObjetoPG
{
public:

	//METODOS PUBLICOS
	GlobosPG(juegoPG* pGame, int px, int py);		//Constructora (Se le pasan los parametros de tamaño de ventana) (EN P1 recibia una textura)
	~GlobosPG();										//Destructora
	//virtual void draw() const;		
	virtual bool onClick();
	virtual void update();										//EN P1 es Bool	(Y no virtual								
	//virtual int getPuntos(){ return AP; };
	virtual void setPinchado(){ pinchado = true; visible = false; };
	int getCentrox(){ return (pRect.x + 30); };		//Metodos necesarios para la implementación del problema 2 de la evaluación
	int getCentroy(){ return (pRect.y + 30); };		//Metodos necesarios para la implementación del problema 2 de la evaluación

private:
	//ATRIBUTOS
	//TexturasSDL* imagen;		//AHORA LO HEREDA Y ES PUBLICO
	float DT;					//Estado de desinflado del globo
	int posX, posY;				//Posicion del globo en x e y	
	bool pinchado;				//Si ha sido explotado o desinflado
	static const int PVIS = 70;	//Probabilidad de que sea visible				
	static const int PDES = 30;	//Probabilidad de que se desinfle.
};

//#endif