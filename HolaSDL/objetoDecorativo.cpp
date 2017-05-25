#include "objetoDecorativo.h"


objetoDecorativo::objetoDecorativo(Juego* ptr, int px, int py, std::string objectID) : Objeto(ptr, px, py)
{
	animado = false;					//Establecemos que el objeto NO está animado a no ser que se especifique en su zona (cambie a true)
	tipo = DECORATIVO;					//Valor por defecto, se actualiza si algún objeto precisa de otro
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
	}

	else if (id == "papelera2"){
		textura = juego->getTextura(Juego::TPapelera2);

		rect.w = 50;
		rect.h = 50;
	}

	else if (id == "papelera3"){
		textura = juego->getTextura(Juego::TPapelera3);

		rect.w = 50;
		rect.h = 50;
	}

	else if (id == "mesaEE"){
		textura = juego->getTextura(Juego::TMesaEE);

		rect.w = 150;
		rect.h = 150;

		rectCollision = rect;

	}
	else if (id == "Humo"){
		textura = juego->getTextura(Juego::THumo);

		rect.w = 768;
		rect.h = 768;
		tipo = SIN_TIPO;			//Porque queremos que el jugador pueda atravesar el objeto 'Humo'

		rectAnim = { 0, 0, 256, 256 };
		rectCollision = { 0, 0, 0, 0 };
		animado = true;
		tipoAnim = "Humo";
	}
	else if (id == "MesaPeque"){
		textura = juego->getTextura(Juego::TMesa);

		rect.w = 69;
		rect.h = 80;

		rectCollision = rect;
		rectCollision.w = rectCollision.h - 15;

	}
	else if (id == "MesaCorazon"){
		textura = juego->getTextura(Juego::TMesaCorazon);

		rect.w = 69;
		rect.h = 80;

		rectAnim = { 0, 0, 128, 150 };
		rectCollision = { rect.x, rect.y, 69, 80 };
		animado = true;
		tipoAnim = "corazon";
	}
	else if (id == "MesaTentaculo"){
		textura = juego->getTextura(Juego::TMesaTentaculo);

		rect.w = 69;
		rect.h = 80;
		rectCollision = rect;
		rectCollision.h = rectCollision.h - 15;

	}
	else if (id == "MesaDoble"){
		textura = juego->getTextura(Juego::TMesaDoble);

		rect.w = 172;
		rect.h = 100;
		rectCollision = rect;
		rectCollision.h = rectCollision.h - 20;

	}
	else if (id == "MesaRota"){
		textura = juego->getTextura(Juego::TMesaRota);

		rect.w = 69;
		rect.h = 80;
		rectCollision = rect;
		rectCollision.h = rectCollision.h - 20;

	}
	else if (id == "MesaRota2"){
		textura = juego->getTextura(Juego::TMesaRota2);

		rect.w = 69;
		rect.h = 80;
		rectCollision = rect;
		rectCollision.h = rectCollision.h - 20;

	}
	else if (id == "VitrinaLib"){
		textura = juego->getTextura(Juego::TVitrinaLib);
		rect.w = 85;
		rect.h = 150;
		rectCollision = rect;
	}
	else if (id == "VitrinaFeto"){
		textura = juego->getTextura(Juego::TVitrinaFeto);

		rect.w = 85;
		rect.h = 150;
		rectCollision = rect;

	}

	else if (id == "Planta1"){
		textura = juego->getTextura(Juego::TPlanta1);

		rect.w = 55;
		rect.h = 150;
		rectCollision = { (rect.x + 15), (rect.y + 80), 20, 20 };
	}
	else if (id == "Planta2"){
		textura = juego->getTextura(Juego::TPlanta2);

		rect.w = 55;
		rect.h = 150;
		rectCollision = { (rect.x + 15), (rect.y + 60), 20, 60 };
	}
	else if (id == "Planta3"){
		textura = juego->getTextura(Juego::TPlanta3);

		rect.w = 55;
		rect.h = 150;
		rectCollision = { (rect.x+15), (rect.y+50), 20, 70 };
	}
	else if (id == "Cafetera"){
		textura = juego->getTextura(Juego::TCafe);

		rect.w = 85;
		rect.h = 150;
		rectCollision = rect;
	}
	else if (id == "Hojas"){
		textura = juego->getTextura(Juego::THojas);

		rect.w = 128;
		rect.h = 128;
	}

	else if (id == "BancoArriba"){
		textura = juego->getTextura(Juego::TBancoUp);

		rect.w = 128;
		rect.h = 32;
	}
	else if (id == "BancoAbajo"){
		textura = juego->getTextura(Juego::TBancoDown);

		rect.w = 128;
		rect.h = 32;
	}
	else if (id == "BancoIzda"){
		textura = juego->getTextura(Juego::TBancoIzdo);

		rect.w = 32;
		rect.h = 128;
		rectCollision = { (rect.x + 24), rect.y, 8, 128 };
	}
	else if (id == "BancoDcha"){
		textura = juego->getTextura(Juego::TBancoDcho);

		rect.w = 32;
		rect.h = 128;
		rectCollision = { rect.x, rect.y, 8, 128 };
	}
	else if (id == "Caja"){
		textura = juego->getTextura(Juego::TCaja);

		rect.w = 128;
		rect.h = 128;
		rectCollision = { (rect.x+20), (rect.y+15), 88, 100 };
	}
	else if (id == "Servers"){
		textura = juego->getTextura(Juego::TServers);

		rect.w = 128;
		rect.h = 120;
		rectCollision = { rect.x, (rect.y+10), 128, 90 };
	}
}

void objetoDecorativo::draw() const {
	if (animado){
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

