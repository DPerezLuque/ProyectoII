#include "EscenaFinal.h"
#include "Player.h"
#include "Boton.h"

EscenaFinal::EscenaFinal(Juego* ptr) : Estado(ptr)
{
	
	type = CINEMATICA_FINAL;
	fondo = juego->getTextura(Juego::TFondoFinal);
	cientifico = juego->getTextura(Juego::TCientifico);
	jugador = new Player(ptr, 100, 600); //Yo que sé, donde esté
	estCinematica = AvanceAlDialogo;
	jugador->changeControlCinematica(true);
	//mensaje = new Dialogo(juego, 250, 330, 500, 150, "");

	//juego->arrayMenu.push_back(new Boton(juego, 0, 0, ptr->getWidth(), ptr->getHeight(), Juego::TBotonFinal, Juego::TBotonFinal, BOTON_FINAL));
	
	dimensionesCientifico.h = 157;
	dimensionesCientifico.w = 51;

	dimensionesFondo.x = dimensionesFondo.y = 0;
	dimensionesFondo.h = ptr->getHeight();
	dimensionesFondo.w = ptr->getWidth();

	contMensajes = 0;
	contTiempo = 0;
	creaMensaje = true;
	//pintaMensaje = false;

}


EscenaFinal::~EscenaFinal()
{
}


void EscenaFinal::update(){
	//Para hacer el update del jugador, lo que pienso hacer es activar un bool para que cuando esté activo
	//En vez de hacer el update como siempre lo que hará será moverse con un pos.x ++ y SIEMPRE A LA DERECHA COMO ESPAÑ..
	
	switch (estCinematica)
	{
	case AvanceAlDialogo:
		//Avanzamos al jugador DESDE LA PUERTA hasta una distancia X que sea enfrente del
		//cientifico, y una vez esté ahí pasaremos al estado DIALOGO
		if (jugador->getRect().x <= 250){
			jugador->update(1);
			cout << jugador->getRect().x << '\n';
		}
		else{
			estCinematica = Textos;
			jugador->changeControlCinematica(false);
			
		}


		break;
	case Textos:

		//En el estado DIALOGO el jugador va a tener la opcion de pulsar para pasar el texto, o si ves que 
		//Es muy complicado pues vas pasando el texto por tiempo. El texto lo cargas tal cual haciamos con las almas pero
		//habría que modificar un poquito el tamaño y tal, o poner más textos a menor cuadrado

		//Evidentemente, en cada vuelta del bucle se dibujan los personajes de la escena

		//Una vez se terminen los dialogos, se pasará al estado SALIDA

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


		if (contTiempo >= 100){

			contTiempo = 0;

			if (contMensajes != 4){
				creaMensaje = true;
				contMensajes++;
			}

			else{
				pintaMensaje = false;
				jugador->changeControlCinematica(true);
				estCinematica = Salida;
			}


		}

		else contTiempo++;

		break;

	case Salida:
		//El jugador avanza hacia la salida, pasando al cientifico (el cual no se mueve, si te ves con ganas de hacer que gire para 
		//verle ir pues bueno) y una vez desaparece de la pantalla se pasa al MENU DE FINAL DE JUEGO.

		if (jugador->getRect().x <= juego->getWidth()-10){
			jugador->update(1);
			cout << jugador->getRect().x << '\n';
		}
		else{
			//fundidoEnNegroToGuapo();
			juego->estado->changeCurrentState(MENU_FINAL);
	}


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

