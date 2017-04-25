#pragma once
#include <SDL_ttf.h>
#include "SDL.h"
#include <iostream>
#include <string>


class Texto
{
public:
	Texto();
	Texto(std::string nombArch, int size);
	virtual ~Texto();

	void close();
	bool load(std::string nombArch, int size);
	SDL_Surface* renderText(std::string text, SDL_Color color) const;
private:
	TTF_Font * pFont;
};

