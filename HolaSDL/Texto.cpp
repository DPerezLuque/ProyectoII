#include "Texto.h"

Texto::Texto()
{
}

Texto::Texto(string nombArch, int size) {
	load(nombArch, size);
}

Texto::~Texto(){
	close();
}

bool Texto::load(string nombArch, int size) {
	pFont = TTF_OpenFont(nombArch.c_str(), size);
	return pFont != nullptr;
}

void Texto::close(){
	if (pFont) {
		//TTF_CloseFont(pFont);
		pFont = nullptr;
	}
}

SDL_Surface* Texto::renderText(std::string text, SDL_Color color) const {
	if (pFont) {
		return TTF_RenderText_Solid(pFont, text.c_str(), color);
	}
	else {
		return nullptr;
	}
}