#include "Cargador.h"


Cargador::Cargador(Juego* pJuego, Player* jugador, SDL_Rect Camera, int ancho, int alto, int posX, int posY) : Interfaz(pJuego, jugador, Camera, ancho, alto, posX, posY)
{
	textura = pJuego->getTextura(Juego::TCargador);

	fuenteCargador = new Texto(pJuego->getTexto(1), 18);
	mensaje = new Textura();
	Black = { 0, 0, 0, 255 }; //RGBA	
	Red = { 175, 20, 20, 255 }; //RGBA	
	mensaje->loadFromText(pRenderer, to_string(player->getBalas()), *fuenteCargador, Black);
}


Cargador::~Cargador()
{
}

void Cargador::update(SDL_Rect Camera){
	mensaje->loadFromText(pRenderer, to_string(player->getBalas()), *fuenteCargador, Black);	
}

void Cargador::draw() const{

	textura->draw(pRenderer, pRect.x, pRect.y, pRect);

	if (player->getBalas() > 0 && !player->isDead()){
		mensaje->loadFromText(pRenderer, to_string(player->getBalas()), *fuenteCargador, Black);
		if (player->getBalas() < 10){
			mensaje->render(pRenderer, pJuego->SCREEN_WIDTH - 44, pJuego->SCREEN_HEIGHT - 50);
		}
		else{ mensaje->render(pRenderer, pJuego->SCREEN_WIDTH - 54, pJuego->SCREEN_HEIGHT - 50); }
	}
	else{
		mensaje->loadFromText(pRenderer, "Recargando", *fuenteCargador, Red);
		mensaje->render(pRenderer, ((pJuego->SCREEN_WIDTH / 2) - 100), ((pJuego->SCREEN_HEIGHT / 2) - 100));
	}
}