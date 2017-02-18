// mainP1.cpp
//Autores: Antonio Cardona Costa y Mario Jiménez Contreras

#include "SDL.h"		// Para utilizar SDL
#include "SDL_image.h"	// para control del sprite
#include "juegoPG.h"	// para el control del juego
#include <iostream>		// la consola: cin / cout
#include "Error.h"
#include <exception>
using namespace std;	// Para cualificar automaticamente con std:: los identificadores de la librería estandar 
//----------------------------------------------------------------------------------------------------------------------


int main(int argc, char* args[]) {  // SDL require esta cabecera 
	system("chcp 1252");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	juegoPG* juego = nullptr;

	//SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Inicio de juego", "Preparado?", NULL);

	try{
		cout << "Creamos nuevo juego. \n";
		juego = new juegoPG;
		juego->run();
	}

	catch (Error & e) { e.mensaje(); } //Si es un error definido por nosotros
	catch (bad_alloc & e) { SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Memoria llena", "No se ha podido crear el recurso", NULL); e.what(); } //Si la memoria esta llena
	catch (out_of_range & e) { SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Fuera de rango", "Intento de acceso fuera de rango del vector", NULL); e.what(); }
	catch (bad_cast & e) { SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Fallo de Cast", "No se ha podido realizar el cast", NULL); e.what(); }
	catch (exception & e) { e.what(); }
	catch (...){ SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error grave", "Causa Desconocida", NULL); } //Si algo falla llamamos a la destructora

	juego->~juegoPG(); //Liberamos recursos
	return 0;
}


//OBJETIVOS
	//1.- Cargar ventana (init pwin, prenderer)
	//2.- Cargar lista de globos (¿Pero cuantos globos quiere?)
	//3.- Mostrar globos en ventana