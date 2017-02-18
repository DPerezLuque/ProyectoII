#pragma once
//#ifndef OBJETO_JUEGO_H
//#define OBJETO_JUEGO_H


class ObjetoJuego
{
public:
	//METODOS PUBLICOS
	ObjetoJuego(){}
	virtual ~ObjetoJuego(){}

	//METODOS DEL ENUNCIADO	
	virtual void draw() const = 0;			//El = 0 hace que el metodo sea abstracto, llamando directamente al del nieto
	virtual void update() = 0;				//Generico: llamar a Draw aunque generalmente se usara el propio de los hijos
	virtual bool onClick() = 0;

};
//#endif
