#include "EscenaFinal.h"
#include "Player.h"

EscenaFinal::EscenaFinal(Juego* ptr) : Estado(ptr)
{
	fondo = juego->getTextura(Juego::TFondoFinal);
	cientifico = juego->getTextura(Juego::TCientifico);
	jugador = new Player(ptr, 500, 500); //Yo que sé, donde esté
	estCinematica = AvanceAlDialogo;

	dimensionesCientifico = jugador->getRect();
	dimensionesFondo.x = dimensionesFondo.y = 0;
	dimensionesFondo.h = ptr->getHeight();
	dimensionesFondo.w = ptr->getWidth();

}


EscenaFinal::~EscenaFinal()
{
}


void EscenaFinal::draw(){
	switch (estCinematica){
		fondo->draw(pRenderer, 0, 0, dimensionesFondo);
		cientifico->draw(pRenderer, 1000, 1000 /*numeros totalmente al azar, hay que ajustarlo*/, dimensionesFondo);
		jugador->draw();
		
	case AvanceAlDialogo:
		//Aqui se dibuja al personaje con la animacion (supongo)
		//El cientifico va estático
		break;
	case Dialogo:
		//Aqui el jugador está estatico, al igual que el cientifico
		break;
	case Salida:
		//Igual que AvanceAlDialogo
		break;
	}
}


void EscenaFinal::update(double delta){
	//Para hacer el update del jugador, lo que pienso hacer es activar un bool para que cuando esté activo
	//En vez de hacer el update como siempre lo que hará será moverse con un pos.x ++ y SIEMPRE A LA DERECHA COMO ESPAÑ..
	
	switch (estCinematica)
	{
	case AvanceAlDialogo:
		//Avanzamos al jugador DESDE LA PUERTA hasta una distancia X que sea enfrente del
		//cientifico, y una vez esté ahí pasaremos al estado DIALOGO
		break;
	case Dialogo:

		//En el estado DIALOGO el jugador va a tener la opcion de pulsar para pasar el texto, o si ves que 
		//Es muy complicado pues vas pasando el texto por tiempo. El texto lo cargas tal cual haciamos con las almas pero
		//habría que modificar un poquito el tamaño y tal, o poner más textos a menor cuadrado

		//Evidentemente, en cada vuelta del bucle se dibujan los personajes de la escena

		//Una vez se terminen los dialogos, se pasará al estado SALIDA
		break;
	case Salida:
		//El jugador avanza hacia la salida, pasando al cientifico (el cual no se mueve, si te ves con ganas de hacer que gire para 
		//verle ir pues bueno) y una vez desaparece de la pantalla se pasa al MENU DE FINAL DE JUEGO.
		break;
	}
}
