#include "Aura.h"

Aura::Aura(Juego* ptr, int px, int py, int ancho, int alto, std::string texto) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TCargador);
	mensaje = new Dialogo(juego, rect.x, rect.y, ancho, alto, texto);
	rect.w = 50;
	rect.h = 50;
	rectCollision = rect;
	activo = false;
	contador = 0;
	contador2 = 0;
	topeUp = rect.y + 15;
	topeDown = rect.y - 15;
}


Aura::~Aura()
{
	delete mensaje;
}

void Aura::onCollision(){
	activo = true;
}

void Aura::draw() const{
	/*
	if (!activo){
	textura->draw(pRenderer, rect.x - juego->camera.x, rect.y - juego->camera.y, rect);
	}
	*/
	textura->draw(pRenderer, rect.x - juego->camera.x, rect.y - juego->camera.y, rect);
	if (activo){
		mensaje->draw();
	}
}
void Aura::update(int delta){
	contador += delta;
	contador2 += delta;

	if (contador > 2 && arriba){
		rect.y++;
		contador = 0;
	}
	else if (contador > 2){
		rect.y--;
		contador = 0;
	}

	if (contador2 > 100){
		arriba = !arriba;
		contador2 = 0;
	}

}
