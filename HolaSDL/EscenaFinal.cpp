#include "EscenaFinal.h"
#include "Player.h"

EscenaFinal::EscenaFinal(Juego* ptr) : Estado(ptr)
{
	type = CINEMATICA_FINAL;
	fondo = juego->getTextura(Juego::TFondoFinal);
	cientifico = juego->getTextura(Juego::TCientifico);
	jugador = new Player(ptr, 250, 570); //Yo que s�, donde est�
	estCinematica = Textos;
	//mensaje = new Dialogo(juego, 250, 330, 500, 150, "");
	
	dimensionesCientifico.h = 157;
	dimensionesCientifico.w = 51;

	dimensionesFondo.x = dimensionesFondo.y = 0;
	dimensionesFondo.h = ptr->getHeight();
	dimensionesFondo.w = ptr->getWidth();

	contMensajes = 0;
	creaMensaje = true;
	//pintaMensaje = false;

}


EscenaFinal::~EscenaFinal()
{
}


void EscenaFinal::update(){
	//Para hacer el update del jugador, lo que pienso hacer es activar un bool para que cuando est� activo
	//En vez de hacer el update como siempre lo que har� ser� moverse con un pos.x ++ y SIEMPRE A LA DERECHA COMO ESPA�..
	
	switch (estCinematica)
	{
	case AvanceAlDialogo:
		//Avanzamos al jugador DESDE LA PUERTA hasta una distancia X que sea enfrente del
		//cientifico, y una vez est� ah� pasaremos al estado DIALOGO
		break;
	case Textos:

		//En el estado DIALOGO el jugador va a tener la opcion de pulsar para pasar el texto, o si ves que 
		//Es muy complicado pues vas pasando el texto por tiempo. El texto lo cargas tal cual haciamos con las almas pero
		//habr�a que modificar un poquito el tama�o y tal, o poner m�s textos a menor cuadrado

		//Evidentemente, en cada vuelta del bucle se dibujan los personajes de la escena

		//Una vez se terminen los dialogos, se pasar� al estado SALIDA

		if (creaMensaje){

			switch (contMensajes)
			{
				case 0:
					mensaje = new Dialogo(juego, 250, 330, 500, 150, "Hola Pedazo de puta");
					pintaMensaje = true;
					creaMensaje = false;
					break;

				case 1:
					mensaje = new Dialogo(juego, 250, 330, 500, 150, "Te odio.");
					pintaMensaje = true;
					creaMensaje = false;
					break;

				case 2:
					mensaje = new Dialogo(juego, 250, 330, 500, 150, "Y lo sabes.");
					pintaMensaje = true;
					creaMensaje = false;
					break;

				case 3:
					mensaje = new Dialogo(juego, 250, 330, 500, 150, "Jajajajajajajaja xD");
					pintaMensaje = true;
					creaMensaje = false;
					break;
			}
		}




		break;

	case Salida:
		//El jugador avanza hacia la salida, pasando al cientifico (el cual no se mueve, si te ves con ganas de hacer que gire para 
		//verle ir pues bueno) y una vez desaparece de la pantalla se pasa al MENU DE FINAL DE JUEGO.
		break;
	}
}

void EscenaFinal::draw(){

	SDL_RenderClear(pRenderer);
	SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	fondo->draw(pRenderer, 0, 0, dimensionesFondo);
	cientifico->draw(pRenderer, 700, 500 /*numeros totalmente al azar, hay que ajustarlo*/, dimensionesCientifico);
	jugador->draw();

	if (pintaMensaje){
		mensaje->draw();
	}
	SDL_RenderPresent(pRenderer);
}