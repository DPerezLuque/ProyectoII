#include "Dialogo.h"


Dialogo::Dialogo(Juego* ptr, int px, int py, int ancho, int alto, std::string texto) : Objeto(ptr, px, py)
{
	White = { 255, 255, 255, 255 };
	mensaje = new Textura();
	escrito = new Texto(juego->getTexto(1), 14);
	cuadro = juego->getTextura(Juego::TDialogo);
	
	mensaje->loadFromText(pRenderer, texto, *escrito, White);
	rect.w = ancho;
	rect.h = alto;
}


Dialogo::~Dialogo()
{
}

void Dialogo::draw() const{
	cuadro->draw(pRenderer, rect.x - juego->camera.x, rect.y - juego->camera.y, rect);
	mensaje->render(pRenderer, (rect.x + 10) - juego->camera.x, (rect.y + 10) - juego->camera.y);
}

