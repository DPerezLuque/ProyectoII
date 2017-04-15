#pragma once
#include <SDL_mixer.h>
#include "SDL.h"
#include <iostream>
#include <string>

using namespace std;

class Musica
{
public:
	Musica();
	Musica(string nombArch);
	~Musica();

	void play();
	void pause();
	void close(); //liberar recursos
	bool load(string const& nombArch);
private:
	Mix_Music *pMusic; //Especifico para mp3,ogg...
};

