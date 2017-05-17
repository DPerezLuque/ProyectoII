#include "Boton.h"

Boton::Boton(Juego* ptr, int px, int py, Juego::Texturas_t tex1, Juego::Texturas_t tex2, collision type) : Objeto(ptr, px, py)
{
	tipo = type;
	//cbOnClick = cb;
	textura1 = juego->getTextura(tex1);
	textura2 = juego->getTextura(tex2);
	
	textura = textura1;
	//visible = true;
	//Position
	rect.x = px;
	rect.y = py;
	rect.w = 300;
	rect.h = 33;

	//auxText = rect;
	rectCollision = rect;
}

Boton::Boton(Juego* ptr, int px, int py, int pw, int ph, Juego::Texturas_t tex1, Juego::Texturas_t tex2, collision type) : Objeto(ptr, px, py)
{
	tipo = type;
	//cbOnClick = cb;
	textura1 = juego->getTextura(tex1);
	textura2 = juego->getTextura(tex2);

	textura = textura1;
	//visible = true;
	//Position
	rect.x = px;
	rect.y = py;
	rect.w = pw;
	rect.h = ph;

	//auxText = rect;
	rectCollision = rect;
}

Boton::~Boton() {}

void Boton::update() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	//cout << x << " " << y << "\n";
	
	if (tipo != BOTON_SANGRE){
		if (dentro(x, y)) {
			textura = textura2;
		}
		else textura = textura1;
	}
	else { changeText(); }

}

void Boton::draw() const {

	//rect.x = (juego->camera.w + juego->camera.x) / 2;
	//rect.y = (juego->camera.h + juego->camera.y) / 2;
	//textura->draw(pRenderer, rect.x, rect.y, rect);
	SDL_Rect auxText;

	//juego->resetCamera();
	auxText.x = juego->camera.w + juego->camera.x;
	auxText.y = juego->camera.h + juego->camera.y;
	auxText.w = rect.w;
	auxText.h = rect.h;
	
	//cout << rect.x << " " << rect.y << " " << auxText.x << " " << auxText.y << "\n";
	
	textura->draw(pRenderer, rect.x, rect.y, rect);
}

void Boton::changeText(){

	if (juego->getSangre())
		textura = textura2;
	else textura = textura1;

}



