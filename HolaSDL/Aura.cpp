#include "Aura.h"


Aura::Aura(Juego* ptr, int px, int py, std::string texto) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TCargador);
	mensaje = new Dialogo(juego, rect.x, rect.y, 350, 150, texto);
	rect.w = 50;
	rect.h = 50;
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
