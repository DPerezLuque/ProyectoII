#include "TexturasSDL.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Error.h"
#include <iostream>
using namespace std;

TexturasSDL::TexturasSDL()
{
	pTexture = nullptr;
	surfText = nullptr;

	//RenderRect es el rectangulo sobre el que se dibujará el objeto
	renderRect.x = 0;
	renderRect.y = 0;
}

TexturasSDL::~TexturasSDL()
{
	SDL_DestroyTexture(pTexture); //Metodo de liberado de memoria de GPU
}

bool TexturasSDL::load(SDL_Renderer* pRenderer, string const& nombArch)
{	
	//Recibe el pRenderer del juego.
	bool success = true;  //Loading success flag
	
	//Load image
	surfText = IMG_Load(nombArch.c_str());  // si usamos string: bmpName.c_str()

	if (surfText == nullptr) {
		throw ErrorTextura("No se ha podido cargar el archivo");
		cout << "Unable to load image " << nombArch.c_str() << "! \nSDL Error: " << SDL_GetError() << '\n';
		success = false;
	}
	else {
		TEXTURE_WIDTH = surfText->w;	//Inicializamos Ancho
		renderRect.w = surfText->w;		
		TEXTURE_HEIGHT = surfText->h;	//Inicializamos Alto
		renderRect.h = surfText->h;
	
		SDL_DestroyTexture(pTexture);									//Limpiamos pTexture de lo que tuviera antes cargado en la GPU
		pTexture = SDL_CreateTextureFromSurface(pRenderer, surfText);	//Obtenemos la nueva textura y la mandamos a la GPU
		SDL_FreeSurface(surfText);										//Eliminar la textura de la CPU
		success = pTexture != nullptr;
		
	}
	return success;
};

void TexturasSDL::render(SDL_Renderer* pRenderer, SDL_Rect const& objRect, SDL_Rect const& frameRect){ //Dibuja animaciones
	//renderRect = DondeRenderizamos en ventana y tamaño, fRect = que frame renderizamos.
	//void render(SDL_Renderer* pRenderer, SDL_Texture* pTexture, SDL_Rect & fRect, SDL_Rect & renderRect); 
	SDL_RenderCopy(pRenderer, pTexture, &frameRect, &objRect);
}

void TexturasSDL::draw(SDL_Renderer* pRenderer, SDL_Rect const& rect)	//Dibuja texturas estaticas
{
	//1º Rect de la pantalla (SDL_Renderer) (pRenderer)
	//2º Textura a dibujar (SDL_Texture) (pTexture)
	//3º Rectangulo con el recorte de la textura almacenada en TEXTURAS_SDL (SDL_Rect) ()
	//4º Rectangulo donde se dibujara en pantalla (SDL_Rect) ()
	//cout << "Ha entrado en TexturasSDL::Draw \n\n";
	SDL_RenderCopy(pRenderer, pTexture, &renderRect, &rect);
};

