#pragma once
#include "Estado.h"

class Play : public Estado
{
public:

	Play(Juego* ptr);
	virtual ~Play();

	void init();

	//void update();
	void update(int delta);
	void draw();

	void newDisparo(ObjetoJuego*po, int posX, int posY);
	void newDisparoEnemigo(int posX, int posY, int targetX, int targetY, int velDis);
	void posPlayer(int& x, int& y);
private:
	void getStats(int i);
	bool gameOver;

	//Texto
	Texto* fuenteCargador;
	Textura* mensaje;
	SDL_Color Black;
	SDL_Color Red;

	//Musica
	vector <string> musicNames;//Vector para almacenar direcciones de canciones
	Musica* cancion; //Auxiliar para llenar el vector de musica
	vector <Musica*> musicFiles;

	int vidaAux = 0;
};

