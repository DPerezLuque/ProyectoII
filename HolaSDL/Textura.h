#pragma once

#include "SDL.h"
#include <iostream>

class Textura
{
public:

	Textura();
	~Textura();

	bool load(SDL_Renderer* pRenderer, std::string const& nombArch);
	void draw(SDL_Renderer* pRenderer, int rectX, int rectY, SDL_Rect const& rect);
	void drawAnimacion(SDL_Renderer* pRenderer, SDL_Rect const& rect, SDL_Rect const& rectaux);

	SDL_Rect rectori;

private:
	
	SDL_Texture* pTextura;

};

