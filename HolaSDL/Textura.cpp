#include "Textura.h"
#include "Juego.h"
#include "SDL_image.h"

Textura::Textura()
{	
	pTextura = nullptr;

	rectori.w = 0;
	rectori.h = 0;
}

Textura::~Textura()
{
	SDL_DestroyTexture(pTextura);
}


bool Textura::load(SDL_Renderer* pRenderer, std::string const& nombArch) {
	 
	SDL_Surface* pTempSurface = nullptr;
	bool error = false;  //Loading success flag
	
						  //Load image
	pTempSurface = IMG_Load(nombArch.c_str());  //Cargamos la imagen 
	if (pTempSurface == nullptr) {
		std::cout << "Unable to load image " << nombArch.c_str() << "! \nSDL Error: " << IMG_GetError() << '\n';
		error = true;
	}
	else {
		delete pTextura;
		pTextura = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
		rectori.h = pTempSurface->h;
		rectori.w = pTempSurface->w;
		SDL_FreeSurface(pTempSurface);
		if (pTextura == nullptr)
			error = true;
	}

	return error;
}


void Textura::draw(SDL_Renderer* pRenderer, SDL_Rect const& rect) {
	SDL_RenderCopy(pRenderer, pTextura, &rectori, &rect); // (render, textura, rect de lo que quieres dibujar, rect destino)
}

void Textura::drawAnimacion(SDL_Renderer* pRenderer, SDL_Rect const& rect, SDL_Rect const& rectaux) {
	SDL_RenderCopy(pRenderer, pTextura, &rectaux, &rect); // (render, textura, rect de lo que quieres dibujar, rect destino)
}

//PARA EL TEXTO:
bool Textura::loadFromText(SDL_Renderer* renderer, std::string text,
	const Texto& font, const SDL_Color color) {
	
	SDL_Surface* textSurface = font.renderText(text, color);
	if (textSurface != nullptr) {	
		cout << "creando surface\n"; //Aquí no entra
		pTextura = SDL_CreateTextureFromSurface(renderer, textSurface);
		if (pTextura != nullptr) {
			ancho = textSurface->w;
			alto = textSurface->h;
		}
		SDL_FreeSurface(textSurface);
	}
	return pTextura != nullptr;
}

void Textura::render(SDL_Renderer* renderer, int x, int y) const {
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = ancho;
	dest.h = alto;
	render(renderer, dest);
}

void Textura::render(SDL_Renderer* renderer, const SDL_Rect& dest,
	SDL_Rect* clip) const {
	if (pTextura) {
		SDL_Rect default_clip = { 0, 0, ancho, ancho };
		if (clip == nullptr) {
			clip = &default_clip;
		}
		SDL_RenderCopy(renderer, pTextura, clip, &dest);
	}
}