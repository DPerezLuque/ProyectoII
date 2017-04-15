#pragma once
#include <SDL_ttf.h>
#include "SDL.h"
#include <iostream>
#include <string>

using namespace std;

class Texto
{
public:
	Texto();
	Texto(string nombArch, int size);
	virtual ~Texto();

	void close();
	bool load(string nombArch, int size);
	SDL_Surface* renderText(string text, SDL_Color color) const;

private:
	TTF_Font * pFont;
};

