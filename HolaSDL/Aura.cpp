#include "Aura.h"

Aura::Aura(Juego* ptr, int px, int py, int ancho, int alto, std::string texto) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TCargador);
	mensaje = new Dialogo(juego, rect.x, rect.y, ancho, alto, texto);
	rect.w = 50;
	rect.h = 50;
	rectCollision = rect;
	activo = false;
	topeUp = rect.y + 15;
	topeDown = rect.y - 15;
	contDestruccion = 0;

	tipo = AURA;
}


Aura::~Aura()
{
	delete mensaje;
	delete this;
}

void Aura::onCollision(collision type){
	
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
	Oscilar(delta);

	if (activo){
		contDestruccion += delta;
		
		if (contDestruccion >= 200){
			destruyeAlma();
		}

	}
}

void Aura:: destruyeAlma(){
	activo = false;
	dead = true;
	delete mensaje;

}
