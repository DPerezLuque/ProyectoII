#include "Cargador.h"


Cargador::Cargador(Juego* pJuego, ObjetoJuego* jugador, int ancho, int alto, int posX, int posY) : Interfaz(pJuego, jugador, ancho, alto, posX, posY)
{
	pJuego->player->getStats(vida, balas, contador);

	textura = pJuego->getTextura(Juego::TCargador);
	fuenteCargador = new Texto(pJuego->getTexto(1), 18);
	mensaje = new Textura();
	Black = { 0, 0, 0, 255 }; //RGBA	
	Red = { 175, 20, 20, 255 }; //RGBA	
	
	mensaje->loadFromText(pRenderer, to_string(balas), *fuenteCargador, Black);
}


Cargador::~Cargador()
{
}

void Cargador::update(){
	pJuego->player->getStats(vida, balas, contador);
	mensaje->loadFromText(pRenderer, to_string(balas), *fuenteCargador, Black);	
}

void Cargador::draw() const{

	textura->draw(pRenderer, pRect.x, pRect.y, pRect);

	if (balas > 0 && !player->isDead()){
		mensaje->loadFromText(pRenderer, to_string(balas), *fuenteCargador, Black);
		if (balas < 10){
			mensaje->render(pRenderer, pJuego->SCREEN_WIDTH - 44, pJuego->SCREEN_HEIGHT - 50);
		}
		else{ mensaje->render(pRenderer, pJuego->SCREEN_WIDTH - 54, pJuego->SCREEN_HEIGHT - 50); }
	}
	else{
		mensaje->loadFromText(pRenderer, "Recargando", *fuenteCargador, Red);
		mensaje->render(pRenderer, ((pJuego->SCREEN_WIDTH / 2) - 100), ((pJuego->SCREEN_HEIGHT / 2) - 100));
	}
}