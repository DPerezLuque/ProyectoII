#include "EscenaFinal.h"
#include "Player.h"
#include "Boton.h"

EscenaFinal::EscenaFinal(Juego* ptr) : Estado(ptr)
{
	
	type = CINEMATICA_FINAL;
	fondo = juego->getTextura(Juego::TFondoFinal);
	cientifico = juego->getTextura(Juego::TCientifico);
	jugador = new Player(ptr, 100, 600); 
	estCinematica = AvanceAlDialogo;
	jugador->changeControlCinematica(true);
	
	dimensionesCientifico.h = 157;
	dimensionesCientifico.w = 51;

	dimensionesFondo.x = dimensionesFondo.y = 0;
	dimensionesFondo.h = ptr->getHeight();
	dimensionesFondo.w = ptr->getWidth();

	contMensajes = 0;
	contTiempo = 0;
	creaMensaje = true;
	//pintaMensaje = false;

	musicNames.push_back("..\\bmps\\Eclipse.mp3");
	//musicNames.push_back("..\\bmps\\Bird.mp3");

	for (int j = 0; j < musicNames.size(); j++) {
		cancion = new Musica();
		cancion->load(musicNames[j]);
		musicFiles.push_back(cancion);
	}

	musicFiles[0]->play();
	//musicFiles[1]->play();
	bird = juego->getEfecto(Juego::bird);
	bird->play();

}


EscenaFinal::~EscenaFinal()
{

	for (int i = 0; i < musicFiles.size(); i++) {
		delete musicFiles[i];
	}

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
				mensaje = new Dialogo(juego, 250, 360, 550, 75, "Mirate. Se te ve orgulloso.");
				pintaMensaje = true;
				creaMensaje = false;
				break;

			case 1:
				mensaje = new Dialogo(juego, 250, 360, 550, 75, "Has destrozado todo mi laboratorio.");
				pintaMensaje = true;
				creaMensaje = false;
				break;

			case 2:
				mensaje = new Dialogo(juego, 250, 360, 550, 75, "Mi querido y silencioso Grant.");
				pintaMensaje = true;
				creaMensaje = false;
				break;

			case 3:
				mensaje = new Dialogo(juego, 250, 360, 550, 75, "Como se siente el perder a un amigo?");
				pintaMensaje = true;
				creaMensaje = false;
				break;

			case 4:
				mensaje = new Dialogo(juego, 250, 360, 550, 75, "Shiloh era especial para ti, verdad?");
				pintaMensaje = true;
				creaMensaje = false;
				break;

			case 5:
				mensaje = new Dialogo(juego, 250, 360, 550, 75, "Tanto como lo es mi mujer para mi.");
				pintaMensaje = true;
				creaMensaje = false;
				break;

			case 6:
				mensaje = new Dialogo(juego, 250, 360, 550, 75, "Y se que no he hecho lo correcto.");
				pintaMensaje = true;
				creaMensaje = false;
				break;

			case 7:
				mensaje = new Dialogo(juego, 250, 360, 550, 75, "Pero le prometi salvarla.");
				pintaMensaje = true;
				creaMensaje = false;
				break;

			case 8:
				mensaje = new Dialogo(juego, 250, 360, 550, 75, "Tu mas que nadie deberias entenderlo.");
				pintaMensaje = true;
				creaMensaje = false;
				break;

			case 9:
				mensaje = new Dialogo(juego, 250, 360, 550, 75, "Ya no puedo retenerte.");
				pintaMensaje = true;
				creaMensaje = false;
				break;

			case 10:
				mensaje = new Dialogo(juego, 250, 360, 550, 75, "Leeme la mente si quieres.");
				pintaMensaje = true;
				creaMensaje = false;
				break;

			case 11:
				mensaje = new Dialogo(juego, 250, 360, 550, 75, "Con ese nuevo poder robado.");
				pintaMensaje = true;
				creaMensaje = false;
				break;

			case 12:
				mensaje = new Dialogo(juego, 250, 360, 550, 75, "Veras que no miento.");
				pintaMensaje = true;
				creaMensaje = false;
				break;

			case 13:
				mensaje = new Dialogo(juego, 250, 360, 550, 75, "Marchate y no causes mas sufrimiento.");
				pintaMensaje = true;
				creaMensaje = false;
				break;

			case 14:
				mensaje = new Dialogo(juego, 250, 360, 550, 75, "Te has liberado. A ti y a tu monstruo.");
				pintaMensaje = true;
				creaMensaje = false;
				break;

			case 15:
				mensaje = new Dialogo(juego, 250, 360, 550, 75, "Vete ahora como un villano.");
				pintaMensaje = true;
				creaMensaje = false;
				break;
			}
		}


		if (contTiempo >= 200){

			contTiempo = 0;

			if (contMensajes != 16){
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
	cientifico->draw(pRenderer, 700, 500, dimensionesCientifico);
	jugador->draw();

	if (pintaMensaje){
		mensaje->draw();
	}
	SDL_RenderPresent(pRenderer);
}

