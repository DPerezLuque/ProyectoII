#pragma once
#include <vector>
#include <string>
#include <stack>

#include "SDL.h"

#include "Textura.h"
#include "EstadoJuego.h"
#include "ObjetoJuego.h"

#include "HUD.h"
#include "Musica.h"
#include "Efecto.h"

//using namespace std;

//860 460
class Juego
{
public:

	Juego();
	~Juego();

	//SCREEN (WINDOW) DIMENSIONS	//680x480
	int const SCREEN_WIDTH = 1000;
	int const SCREEN_HEIGHT = 750;

	//TEXTURE TYPES
	enum Texturas_t {
		TPlayer, TEnemy, TBulletPlayer, TBulletEnemy, TCheck, TEnemyPlanta, TRino, TBarraVida, THumo,
		TBotiquin, TBPlayA, TBPlayE , TBOptionsA, TBOptionsE, TBExitA, TBExitE, TBControlsA, TBControlsE, TBSangreA, TBSangreE,
		TBFilterA, TBFilterE, TBMenuA, TBMenuE, TBRetryA, TBRetryE, TBResumeA, TBResumeE, 
		TFondo, TControles, TVidaLlena, TVidaVacia, TDashLleno,
		TDashVacio, TCargador, TDialogo, TPapelera1, TPapelera2, TPapelera3, TMesaEE, 
		TMesa, TMesaCorazon, TMesaTentaculo, TMesaDoble, TMesaRota, TMesaRota2,
		TBobina, TAura, TPlanta1, TPlanta2, TPlanta3, TVitrinaLib, TVitrinaFeto,
		TEnemigoBomba, TBalaBomba, TExplosionBomba, TSangre1, TSangre2, TSangre3, 
		TCafe, THojas, TBobinaRota, TLogo, TFiltro,TSpider,TBalaRalentizadora, 
		TBancoDcho, TBancoIzdo, TBancoUp, TBancoDown, TBloqueo, TBloqueo2, TKey, TCaja, TServers,
		TFondoFinal, TCientifico, TBotonFinal,

	};

	//PUBLIC VARIABLES
	SDL_Renderer* pRenderer;
	SDL_Window* pWindow;
	SDL_Color pcolor;
	Textura * pTexture;
	SDL_Event e;

	//OPTIONS MENU BUTTONS
	bool sangre = true; //Editado desde opciones, usado por los enemigos.
	bool getSangre(){ return sangre; }
	void setSangre(){ sangre = !sangre; }

	bool tieneLlave = false;
	void quitaLlave(){ tieneLlave = false; }
	bool getLlave(){ return tieneLlave; }

	bool filtro = true; //Editado desde opciones
	bool getFiltro(){ return filtro; }
	void setFiltro(){ filtro = !filtro; }

	bool checkpoint = false;
	bool getCheck(){ return checkpoint; }
	void setCheck(bool coso){ checkpoint = coso; }
	void setDebugBool(bool nuevoDebug){ debugPlayer = nuevoDebug; }

	int x, y;

	//GAME TIME (GLOBAL)
	float delta;
	Uint32 lastUpdate;

	//VELOCITY (PLAYER)
	static const int VPLAYER = 10;
	int mVelX, mVelY;

	//STATE MANAGER
	EstadoJuego* estado;
	std::stack<EstadoJuego*> states;
	EstadoJuego * pause;

	//STACK
	void changeState(EstadoJuego* newSt);
	void pushState(EstadoJuego* newState);
	void popState();
	EstadoJuego* topEstado();

	//GLOBAL ARRAYS
	std::vector<ObjetoJuego*> arrayObjetos;		//ALL OBJECTS IN THE SCENE (DYNAMIC)
	std::vector<ObjetoJuego*> enemyArray;		//ENEMIGOS
	std::vector<ObjetoJuego*> playerBullets;	//BALAS PERSONAJE
	std::vector<ObjetoJuego*> enemyBullets;		//BALAS ENEMIGOS 
	std::vector<ObjetoJuego*> arrayMenu;		//OBJETOS DEL MENU
	std::vector<ObjetoJuego*> objVisible;		//OBJETOS VISIBLES EN PANTALLA
	std::vector <HUD*> elemInterfaz;			//ELEMENTOS INTERFAZ

	//PLAYER
	ObjetoJuego * player;
	bool debugPlayer;

	//CAMERA LEVEL
	SDL_Rect camera;

	//INITS
	bool initSDL();
	bool initMedia();

	//GAME MANAGER FUNCTIONS
	void run();
	void handle_events();
	void updateDirection();
	void resetCamera() { camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT }; };

	bool checkCollision(ObjetoJuego * a, ObjetoJuego * b);
	bool touchesWall(SDL_Rect a);
	bool checkWallCollisions(SDL_Rect a, SDL_Rect b);	

	//CLOSERS
	void cleanArrays();
	void freeMedia();
	void closeSDL();
	
	//SETTERS
	void setSalir() { exit = true;}
//	void setGameOver() { GO = true; }
	bool isInScreen(SDL_Rect rect);
	void addToScreen(ObjetoJuego * obj);
	//void addToScreen(Tilemap::Tile * t);

	//GETTERS
	SDL_Renderer* getRender() const { return pRenderer; }
	SDL_Rect getCamera(){ return camera; }
	Textura* getTextura(Texturas_t et) const { return arrayTex[et]; }
	void getMousePos(int & mpx, int & mpy) const;
	int getHeight() const {return SCREEN_HEIGHT;}
	int getWidth() const {	return SCREEN_WIDTH;}
	int getVelX(){ return mVelX; }
	int getVelY(){ return mVelY; }
	bool getDash(){ return dashing; }
	void setDash(bool dash){ dashing = dash; }

	//CREA COSAS
	void creaAlmas(int, int, std::string);//<--------- OBSOLETO
	void spawnObjetos(char, int, int, std::string);	//Identificador, posicionX, posicionY, String por si es un alma (opcional)

	//EFECTOS
	enum Sonidos_t { disparoPlayer, disparoSpider, aliento, button, death, explosion, punch };
	vector <string> effectNames;//Vector para almacenar direcciones de canciones
	Efecto* efecto; //Auxiliar para llenar el vector de efectos
	vector <Efecto*> effectFiles;

	Efecto* getEfecto(Sonidos_t eff){ return effectFiles[eff]; }

	//FONTS
	enum Fuentes { Arial, };
	string getTexto(int fun) { return nombreFuentes[fun]; }
	bool dashing = false;
	bool getDASH(){ return dashAux; }
	void setDASH(bool dash){dashAux = dash;	}
	void setRecargar(bool re){ recargar = re; }
	bool getRecargar(){ return recargar; }

private:

	bool exit, GO;

	bool dashAux = false;
	bool recargar = false;
	//ARRAYS
	std::vector<std::string> texturas;
	std::vector<Textura*> arrayTex;
	///TEXT
	std::vector<Texto> arrayFuentes;
	std::vector<string> nombreFuentes;
	std::vector<string> VectTextosAlma;

	Texto textoAux;

	
	int contDash;
};

