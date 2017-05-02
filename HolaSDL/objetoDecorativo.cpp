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
		tipo = "e";
	}

	else if (id == "papelera2"){
		textura = juego->getTextura(Juego::TPapelera2);

		rect.w = 50;
		rect.h = 50;

		rectCollision = rect;
		tipo = "e";
	}

	else if (id == "papelera3"){
		textura = juego->getTextura(Juego::TPapelera3);

		rect.w = 50;
		rect.h = 50;

		rectCollision = rect;
		tipo = "e";
	}

	else if (id == "mesaEE"){
		textura = juego->getTextura(Juego::TMesaEE);

		rect.w = 100;
		rect.h = 100;

		rectCollision = rect;
		tipo = "e";
	}
	else if (id == "Humo"){
		textura = juego->getTextura(Juego::THumo);

		rect.w = 768;
		rect.h = 768;

		rectAnim = { 0, 0, 256, 256 };
		rectCollision = { 0, 0, 0, 0 };
		tipo = "a";
		tipoAnim = "Humo";
	}
	else if (id == "MesaPeque"){
		textura = juego->getTextura(Juego::TMesa);

		rect.w = 96;
		rect.h = 112;

		rectCollision = rect;
		tipo = "e";
	}
	else if (id == "MesaCorazon"){
		textura = juego->getTextura(Juego::TMesaCorazon);

		rect.w = 96;
		rect.h = 112;

		rectAnim = { 0, 0, 128, 150 };
		rectCollision = { 0, 0, 96, 90 };
		tipo = "a";
		tipoAnim = "corazon";
	}	
	else if (id == "MesaTentaculo"){
		textura = juego->getTextura(Juego::TMesaTentaculo);

		rect.w = 96;
		rect.h = 112;		
		rectCollision = rect;
		tipo = "e";
	}
	else if (id == "MesaDoble"){
		textura = juego->getTextura(Juego::TMesaDoble);

		rect.w = 192;
		rect.h = 112;
		rectCollision = rect;
		tipo = "e";
	}
	else if (id == "MesaRota"){
		textura = juego->getTextura(Juego::TMesaRota);

		rect.w = 96;
		rect.h = 112;
		rectCollision = rect;
		tipo = "e";
	}
	else if (id == "MesaRota2"){
		textura = juego->getTextura(Juego::TMesaRota2);

		rect.w = 96;
		rect.h = 112;
		rectCollision = rect;
		tipo = "e";
	}
}

void objetoDecorativo::draw() const {
	if (tipo == "a"){
		textura->drawAnimacion(pRenderer, rect.x - juego->camera.x, rect.y - juego->camera.y, rect, rectAnim);
	}
	else{		
		textura->draw(pRenderer, rect.x - juego->camera.x, rect.y - juego->camera.y, rect);		
	}
}

void objetoDecorativo::update(int delta) {
	if (tipoAnim == "corazon"){
		contador += delta;
		if (contador > 10){
			animacionBasica();
			contador = 0;
		}
	}
	else if (tipoAnim == "Humo"){
		contador += delta;
		if (contador > 50){
			animacionBasica();
			contador = 0;
		}		
	}
	else{} //Estatico, sin animacion
	//Colision
	if (juego->checkCollision(this, juego->arrayObjetos[0]))
		onCollision();
}


void objetoDecorativo::animacionBasica(){ //Para el paso de frames
	if (tipoAnim == "corazon"){
		if (rectAnim.x >= 128){
			rectAnim.x = 0;
		}
		else {
			rectAnim.x += 128;
		}
	}
	else if (tipoAnim == "Humo"){
		if (rectAnim.x >= 768){
			rectAnim.x = 0;
		}
		else {
			rectAnim.x += 256;
		}
	}
}

