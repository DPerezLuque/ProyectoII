//Recursos
#include <iostream>
#include <string>
#include <exception>
//SDL
#include "SDL.h"
#include "SDL_image.h"
//Clases Propias
#include "juegoPG.h"
#include "Error.h"
//Escenas
#include "MenuPG.h"		//Necesario para llamar a las constructoras
#include "GameOver.h"
#include "Pausa.h"
#include "PlayPG.h"
using namespace std;

//////////////////////////////CONSTRUCTORES E INICIALIZADORES/////////////////////////////////////

juegoPG::juegoPG(){
	estadoPlay = false;

	rectBG.h = 720;
	rectBG.w = 1280;
	rectBG.x = 0;
	rectBG.y = 0;
	
	//inicializamos los punteros y atributos
	pWindow = nullptr;				//The window we'll be rendering to
	pRenderer = nullptr;			//The renderer by the window

	//EVENTOS
	error = false;					//Variable de estado Error
	exit = false;					//Variable de estado exit

	//Inicializamos SDL y Media
	InitSDL();
	initMedia();	

	//Empezamos en el menu
	pila_estado.push(new MenuPG(this));
}

bool juegoPG::InitSDL()
{
	bool success = true; //Initialization flag

	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL could not initialize! \nSDL_Error: " << SDL_GetError() << '\n';
		success = false;
	}
	else {
		IMG_Init(IMG_INIT_PNG);
		//Create window: SDL_CreateWindow("SDL Hello World", posX, posY, width, height, SDL_WINDOW_SHOWN);
		pWindow = SDL_CreateWindow("ExplotaGlobos", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);		//CON ESTO CREAMOS LA VENTANA
		if (pWindow == nullptr){
			cout << "Window could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
			success = false;
		}
		else {
			//Get window surface:
			pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);	//CON ESTO CREAMOS EL RENDERIZADOR DE LA VENTANA
			SDL_SetRenderDrawColor(pRenderer, 0, 80, 0, 255); //Set background color to green
			if (pRenderer == nullptr){
				cout << "Renderer could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
				success = false;
			}
		}
	}
	//cout << " SDL inicializado " << endl;
	return success;
};

void juegoPG::initMedia(){
	//Almacenar la textura en cada instancia de los objetos
	nombreTexturas = { "../bmps/enter.jpg", 
					"../bmps/perso.png", 
					"../bmps/bala.png",
					"../bmps/TPremio.png",
					"../bmps/BotonMenu.png",
					"../bmps/BotonResume.png",
					"../bmps/BotonExit.png",
					"../bmps/BotonPlay.png",
					"../bmps/BotonScore.png",
	};

	//Carga de texturas (Metodo 1)
		texturas[TFondo] = new TexturasSDL();		//Puntero a un nuevo objeto de tipo TexturasSDL
		texturas[TFondo]->load(pRenderer, nombreTexturas[0]);
		texturas[TPerso] = new TexturasSDL();
		texturas[TPerso]->load(pRenderer, nombreTexturas[1]);
		texturas[TBala] = new TexturasSDL();		//Puntero a un nuevo objeto de tipo TexturasSDL
		texturas[TBala]->load(pRenderer, nombreTexturas[2]);
		texturas[TPremio] = new TexturasSDL();		//Puntero a un nuevo objeto de tipo TexturasSDL
		texturas[TPremio]->load(pRenderer, nombreTexturas[3]);
		texturas[TBMenu] = new TexturasSDL();
		texturas[TBMenu]->load(pRenderer, nombreTexturas[4]);
		texturas[TBResume] = new TexturasSDL();
		texturas[TBResume]->load(pRenderer, nombreTexturas[5]);
		texturas[TBExit] = new TexturasSDL();
		texturas[TBExit]->load(pRenderer, nombreTexturas[6]);
		texturas[TBPlay] = new TexturasSDL();
		texturas[TBPlay]->load(pRenderer, nombreTexturas[7]);
		texturas[TBScore] = new TexturasSDL();
		texturas[TBScore]->load(pRenderer, nombreTexturas[8]);
}

//////////////////////////////////DESTRUCTORA Y LIBERADORES///////////////////////////////////////

juegoPG::~juegoPG()
{

}

bool juegoPG::onExit(){
	while (pila_estado.size() > 0) {
		popState();
	}
	freeMedia();	//Destruimos objetos y texturas
	closeSDL();		//Cierra SDL
	exit = true;
	return true;
};

void juegoPG::freeMedia(){
	//Destructor de texturas
	//cout << "Se va a proceder a eliminar las texturas";
	delete(texturas[TFondo]);
	delete(texturas[TPerso]);
	delete(texturas[TBala]);
	delete(texturas[TPremio]);
	delete(texturas[TBExit]);
	delete(texturas[TBMenu]);
	delete(texturas[TBResume]);
	delete(texturas[TBScore]);
	delete(texturas[TBPlay]);
}

void juegoPG::closeSDL()
{
	SDL_DestroyRenderer(pRenderer);
	pRenderer = nullptr;

	SDL_DestroyWindow(pWindow);
	pWindow = nullptr;

	SDL_Quit();
};

///////////////////////////// METODOS DE FUNCIONAMIENTO //////////////////////////////////////////////////

void juegoPG::run()
{
	if (!error) {
		Uint32 MSxUpdate = 500;
		//cout << "Pulsado el boton PLAY \n";
		Uint32 lastUpdate = SDL_GetTicks();
		//cout << "RUN de juegoPG: procedemos a llamar al render por primera vez \n";
		render();
		handle_event();
		while (!exit && !gameOver) {  //ESTO ES EL MAIN LOOP
			if (SDL_GetTicks() - lastUpdate >= MSxUpdate){ // while(elapsed >= MSxUpdate)
				//Funcionamiento de cada estado
				render();
				getCurrentState()->update();
				//Onclick llamado al pulsar click con el raton en el gestor de eventos

				lastUpdate = SDL_GetTicks();
			}
			handle_event();
		}

		if (exit) cout << "EXIT detectado, cerrando aplicación. \n";
		else { 
			//cout << "FELICIDADES!! Has terminado el juego con " << puntos << " puntos";
			//string str = "Puntuacion: " + to_string(points);
			//SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Fin de juego", (str).c_str(), nullptr);
			}
		}
		SDL_Delay(1000); //cin.get();
};

void juegoPG::MostrarPuntuacion(){ //LLamado desde GameOver
	string str = "Puntuacion: " + to_string(points);
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Fin de juego", (str).c_str(), nullptr);
}
void juegoPG::render(){
	//Limpiamos el renderer
	SDL_RenderClear(pRenderer);
	
	texturas[0]->draw(pRenderer, rectBG);
	getCurrentState()->draw();
	
	//Show the window
	SDL_RenderPresent(pRenderer);
}


////////////////////GESTION DE ESTADOS

void juegoPG::changeState(EstadoJuego* nuevo){
	cout << "Solicitado change State.\n";
	EstadoJuego* aux;
	aux = pila_estado.top();
	popState();	//quita de la pila
	pushState(nuevo);
	delete (aux);
}

void juegoPG::pushState(EstadoJuego* nuevo){
	pila_estado.push(nuevo);
}

void juegoPG::popState(){
	cout << "Eliminamos el estado del top de la pila\n";
	//if (typeid(pila_estado.top()) == typeid(Pausa)) paused = true;
	pila_estado.pop();
}

void juegoPG::setSalir(){
	onExit();
}

/////////////////////////////GESTION DE EVENTOS

void juegoPG::handle_event(){
	SDL_Event e;
	if (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) onExit();
		else if (e.type == SDL_MOUSEBUTTONUP) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				cout << "CLICK DETECTADO" << endl;
				pClickX = e.button.x;
				pClickY = e.button.y;
				getCurrentState()->onClick(); //Para que valga para cualquier escena
			}
			// else if(...)    
		}
		else if (e.type == SDL_KEYUP) {		//Evento de pulsación de la tecla P para el ejercicio 1 de la evaluación
			if (e.key.keysym.sym == SDLK_ESCAPE && estadoPlay){			//Vemos si la tecla pulsada es la 
				cout << "Pausa desde Juego\n";
				//changeState(new Pausa(this));
				pushState(new Pausa(this));
			}
		}
	}
};
