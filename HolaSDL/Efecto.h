#pragma once
#include <SDL_mixer.h>
#include "SDL.h"
#include <iostream>
#include <string>

using namespace std;

class Efecto
{
public:
	Efecto();
	Efecto(string nombArch);
	~Efecto();

	void play();
	void pause();
	void close(); //liberar recursos
	bool load(string const& nombArch); 
private:
	Mix_Chunk *pChunk; //especial para wav
};

