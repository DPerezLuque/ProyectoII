#pragma once
//#ifndef TEXTURAS_SDL_H
//#define TEXTURAS_SDL_H
//#include "juegoPG.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>
using namespace std;
//#endif

class TexturasSDL
{
public:
	//Métodos Publicos
	TexturasSDL();
	~TexturasSDL();
	void draw(SDL_Renderer* pRenderer, SDL_Rect const& rect); //Dibuja estaticos
	void render(SDL_Renderer* pRenderer, SDL_Rect const& objRect, SDL_Rect const& frameRect); //Dibuja animaciones
	bool load(SDL_Renderer* pRenderer, string const& nombArch);
	//int getH(){ return TEXTURE_HEIGHT; };		//Devuelve el alto de la textura
	//int getW(){ return TEXTURE_WIDTH; };		//Devuelve el ancho de la textura



private:
	//ATRIBUTOS
	SDL_Rect renderRect;		//
	SDL_Surface* surfText;		//
	SDL_Texture* pTexture;		//Donde almacenaremos la textura del objeto
	int TEXTURE_WIDTH;
	int TEXTURE_HEIGHT;
	//Métodos Privados
};

