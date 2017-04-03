#pragma once

#include "SDL.h"
#include <iostream>
#include "Texto.h"

class Textura
{
public:

	Textura();
	~Textura();

	bool load(SDL_Renderer* pRenderer, std::string const& nombArch);
	void draw(SDL_Renderer* pRenderer, SDL_Rect const& rect);
	void drawAnimacion(SDL_Renderer* pRenderer, SDL_Rect const& rect, SDL_Rect const& rectaux);

	bool Textura::loadFromText(SDL_Renderer* renderer, std::string text,
		const Texto& font, const SDL_Color color);
	SDL_Rect rectori;

private:
	int ancho, alto;
	SDL_Texture* pTextura;

};

