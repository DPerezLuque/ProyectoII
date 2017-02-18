#include "PlayPG.h"
#include "Error.h"		//Necesario para hacer errores
#include "GlobosPG.h"	//Necesario para llamar a la constructora
#include "Mariposa.h"	//Necesario para llamar a la constructora
#include "Premio.h"		//Necesario para llamar a la constructora
#include "GameOver.h"
#include "Personaje.h"

using namespace std;


//PlayPG::PlayPG(juegoPG* pGame, bool pausa)
PlayPG::PlayPG(juegoPG* pGame)
{
	pJuego = pGame;
	srand(1);
	//cantGlobos = 5;
	puntos = 0;
	pinchados = 0;
	initObjects();
	objPinch = false;
	pJuego->cambiaEstadoPlay();
}


void PlayPG::initObjects(){

	//if (cantGlobos + 2 < 0) throw out_of_range("El tamaño del vector es negativo");
	vObjetos.resize(1 + 2); //Cant de globos + 1 mariposa + 1 premio


	for (unsigned int i = 0; i < vObjetos.size(); i++){
		if (i < 0 || i >= vObjetos.size()) throw Error("Fuera de rango");
		if (i < 1) //Los objetos son globos
		{
			//cout << "Ha entrado en el bucle de initMedia llamado por la constructora de juegoPG\n";
			posObjX = rand() % (pJuego->getScreenW() - 100);	//Generamos una nueva posición aleatoria en x
			posObjY = rand() % (pJuego->getScreenH() - 100);	//Generamos una nueva posición aleatoria en y
			//Constructora de Globo (pJuego, posicionx, posiciony)
			Personaje* pPers = dynamic_cast<Personaje*> (vObjetos[i]); //NUEVO COSO
			pPers = new Personaje(pJuego);
			vObjetos[i] = pPers;
		}
		else if (i == cantGlobos) //El objeto es mariposa
		{
			posObjX = rand() % (pJuego->getScreenW() - 100);	//Generamos una nueva posición aleatoria en x
			posObjY = rand() % (pJuego->getScreenH() - 100);	//Generamos una nueva posición aleatoria en y
			//Constructora de mariposa (pJuego, posicionx, posiciony)
			Mariposa* pMari = dynamic_cast<Mariposa *> (vObjetos[i]);
			pMari = new Mariposa(pJuego, posObjX, posObjY);
			vObjetos[i] = pMari;
		}
		else { //El objeto es el regalo
			posObjX = rand() % (pJuego->getScreenW() - 100);	//Generamos una nueva posición aleatoria en x
			posObjY = rand() % (pJuego->getScreenH() - 100);	//Generamos una nueva posición aleatoria en y
			//Constructora de premio (pJuego, posicionx, posiciony)
			Premio* pPrem = dynamic_cast<Premio*> (vObjetos[i]);
			pPrem = new Premio(pJuego, posObjX, posObjY);
			vObjetos[i] = pPrem;
		}

	}//fin del for
}


bool PlayPG::isGameOver(){
	/*if (pinchados >= cantGlobos){
		pJuego->changeState(new GameOver(pJuego));
	}
	return (pinchados >= cantGlobos);*/
	return pinchados > 23;
}

void PlayPG::freeObjects(){
	for (unsigned int i = 0; i < vObjetos.size(); i++){
		delete (vObjetos[i]);
	}
}

void PlayPG::newBaja(ObjetoJuego* obj){
	GlobosPG* p = dynamic_cast<GlobosPG*> (obj); //Cast para llamar al método del globo que lo marca como pinchado
//	p->setPinchado();
	pinchados += 1;
}

void PlayPG::newPuntos(ObjetoJuego* obj){
	ObjetoPG* p = dynamic_cast<ObjetoPG*> (obj); //Cast para obtener los puntos del objeto
	puntos += p->getPuntos();
}

void PlayPG::newPremio(ObjetoJuego* obj){
	Mariposa* p = dynamic_cast<Mariposa*> (obj); //Cast para llamar a método que confirme si el premio esta activado
	if (p->aparecePremio()){
		premioActivado = true;
		contadorClicks = 0;
	}
}

void PlayPG::update(){

	for (unsigned int i = 0; i < vObjetos.size(); i++){
		vObjetos[i]->update();
	}

	//GESTION DE PREMIO 
	//La posicion de la mariposa en el vObjetos es cantGlobos y la del premio cantGlobos+1
	Mariposa* pMari = dynamic_cast<Mariposa *> (vObjetos[cantGlobos]);
	Premio* pPrem = dynamic_cast<Premio *> (vObjetos[cantGlobos + 1]);
	// CUANDO MARIPOSA ACTIVE EL PREMIO
	if (premioActivado){	//Si el contador de mariposa ha llegado a 3 visible = true
		pPrem->hacerVisible(); //reiniciamos contador de clicks (tenemos 3 intentos)
	}
	// CUANDO SE CLICKE TRES VECES SIN DARLE AL PREMIO
	if (contadorClicks >= 3) {

		pPrem->reiniciarPremio();
		premioActivado = true;
	}
	isGameOver();
}

void PlayPG::onClick(){
	if (premioActivado) { contadorClicks++; }	//Si el premio esta activo añadimos 1 al computo de clicks

	unsigned int i = 0;
	while (i < vObjetos.size() && !objPinch){
		if (vObjetos[i]->onClick()){			//Llamamos el onclick del objeto
			//AHORA LOS PUNTOS SE ACTUALIZAN DESDE EL METODO ONCLICK DEL OBJETO que llamará al metodo newPuntos de JUEGO
			objPinch = true;	//Informa que ya se ha pinchado un objeto en esta posición para que no siga el bucle
		}
		i++;
	}
	if (objPinch) objPinch = false;	//Volvemos al estado inicial una vez acabe
}

PlayPG::~PlayPG()
{
	pJuego->setPuntos(puntos);
	pJuego->cambiaEstadoPlay();	
	freeObjects();
}
