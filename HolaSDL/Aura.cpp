#include "Aura.h"

Aura::Aura(Juego* ptr, int px, int py, int ancho, int alto, std::string texto) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TCargador);
	mensaje = new Dialogo(juego, rect.x, rect.y, ancho, alto, texto);
	rect.w = 50;
	rect.h = 50;
	rectCollision = rect;
	activo = false;
}


Aura::~Aura()
{
	delete mensaje;
}

void Aura::onCollision(){
	std::cout << "colision con Aura\n";
	activo = true;
}

void Aura::draw() const{
	textura->draw(pRenderer, rect.x - juego->camera.x, rect.y - juego->camera.y, rect);
	if (activo){
		mensaje->draw();
	}
}
