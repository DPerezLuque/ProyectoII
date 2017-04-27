#include "objetoDecorativo.h"


objetoDecorativo::objetoDecorativo(Juego* ptr, int px, int py, std::string objectID) : Objeto(ptr, px, py)
{
	setObjectFromString(objectID);		//Creamos el objeto deseado.
										//Dentro de cada espacio de creación independiente™ (Los else if)
										//Se pueden modificar las condiciones del objeto.
}


objetoDecorativo::~objetoDecorativo()
{
}

//Elegimos una textura en función del tipo de objeto que quieras crear, dado por el ID
void objetoDecorativo::setObjectFromString(std::string id){
	
	if (id == ""){
		cout << "ERROR: un ObjetoDecorativo tiene un espacio en su parámetro ID. No quieres que eso pase. \n";
	}
	else if (id == "papelera1"){
		textura = juego->getTextura(Juego::TPapelera1);

		rect.w = 50;
		rect.h = 50;

		rectCollision = rect;
	}

	else if (id == "papelera2"){
		textura = juego->getTextura(Juego::TPapelera2);

		rect.w = 50;
		rect.h = 50;

		rectCollision = rect;
	}

	else if (id == "papelera3"){
		textura = juego->getTextura(Juego::TPapelera3);

		rect.w = 50;
		rect.h = 50;

		rectCollision = rect;
	}

	else if (id == "mesaEE"){
		textura = juego->getTextura(Juego::TMesaEE);

		rect.w = 100;
		rect.h = 100;

		rectCollision = rect;
	}
}

