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

	void draw(SDL_Renderer* pRenderer, int rectX, int rectY, SDL_Rect const& rect);
	void drawAnimacion(SDL_Renderer* pRenderer, int rectX, int rectY, SDL_Rect const& rect, SDL_Rect const& rectaux);
	void drawAnimacion(SDL_Renderer* pRenderer, SDL_Rect const& rect, SDL_Rect const& rectaux);

	bool loadFromText(SDL_Renderer * pRender, std::string texto, Texto const& font, SDL_Color color = { 0, 0, 0, 255 });
	void render(SDL_Renderer* renderer, int x, int y) const;
	void render(SDL_Renderer* renderer, SDL_Rect const& dest, SDL_Rect* clip = nullptr) const;

	SDL_Rect rectori;

private:
	int ancho, alto;
	SDL_Texture* pTextura;

};

