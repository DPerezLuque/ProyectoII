#pragma once
class EstadoJuego
{
	/*Todos los estados comparten la ventana, el renderizador y
	  los eventos.Y tiene la misma estructura:	
	-Vector de objetos del juego
		- draw : indica a los objetos del vector que se dibujen
		- update : indica a los objetos del vector que se actualicen
		- onClick : avisa del evento a los objetos del vector	
	*/
public:
	EstadoJuego()
	{
	}
	virtual void draw() const = 0;			//El = 0 hace que el metodo sea abstracto, llamando directamente al del nieto
	virtual void update() = 0;				//Generico: llamar a Draw aunque generalmente se usara el propio de los hijos
	virtual void onClick() = 0;

	virtual ~EstadoJuego()
	{
	}
};

