#pragma once
#include "EstadoPG.h"

class PlayPG: public EstadoPG {
public:
	//PlayPG(juegoPG* pGame, bool pausa);
	PlayPG(juegoPG* pGame);
	~PlayPG();
	//Enteros
	int getPuntos(){ return puntos; };	
	int getCantGlobos(){ return cantGlobos; };
	int getClicks(){ return contadorClicks; };
	int setClicks(){ contadorClicks = +1; };
	//Booleanos
	bool getPremioActivo(){ return premioActivado; };
	bool isGameOver();
	bool getObjPinch(){ return objPinch; };
	//Void
	void setPremioActivo(){ premioActivado = !premioActivado; };	
	void desactivaPremio(){ premioActivado = false; };
	void setObjPinch(bool m){ objPinch = m; };
	void newBaja(ObjetoJuego* obj);		//Solo llamado por globos, aumenta la cantidad de pinchados
	void newPuntos(ObjetoJuego* obj);	//Lee los AP
	void newPremio(ObjetoJuego* obj);	//Pone a true la variable premioActivado
	void initObjects(); //Constructora de objetos
	void freeObjects(); //Destructora de objetos
	void update();
	void onClick();
	/*
	//Menu pausa
	void cargaEstado(int punctured, int points, int ballonQuant, vector<ObjetoJuego*> vObjects, bool activePrice);
	*/

private:
	
	int cantGlobos;							//Cantidad total de globos con los que comparar pinchados	
	int posObjX;							//Posicion de globo en X
	int posObjY;                            //Posicion de globo en Y

	bool objPinch;							//Variable para determinar si se ha pinchado un objeto en este click Ej.3 evaluación
	bool premioActivado;

	int puntos;								//Contador de puntos
	int pinchados;							//Cuantos globos van pinchados						
	int contadorClicks = 0;					//Se usará para contar los clicks con el Premio, si el número llega a 3, visible = false

};


