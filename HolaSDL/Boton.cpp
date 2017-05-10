#include "Boton.h"

Boton::Boton(Juego* ptr, int px, int py, Juego::Texturas_t tex1, Juego::Texturas_t tex2, collision type) : Objeto(ptr, px, py)
{
	tipo = type;
	//cbOnClick = cb;
	textura1 = juego->getTextura(tex1);
	textura2 = juego->getTextura(tex2);
	
	textura = textura1;
	//visible = true;

	rect.w = 300;
	rect.h = 33;

	rectCollision = rect;
}


Boton::~Boton() {}

void Boton::update() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	//cout << x << " " << y << "\n";
	
	if (dentro(x, y)) {
		textura = textura2;
	}
	else textura = textura1;

}




