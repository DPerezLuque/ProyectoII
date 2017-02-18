#pragma once
//#ifndef MUSICA_H
//#define MUSICA_H
#include "juegoPG.h"


class Musica
{
public:
	Musica();
	~Musica();
	void play();
	void close();
	void load();
private:
	//Mix_Chunk *pMusic; //Especifico para wav

};
//#endif
