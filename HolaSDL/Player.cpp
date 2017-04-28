#include "Player.h"
#include "Checkpoint.h"
#include <iostream>

typedef unsigned int uint;

Player::Player(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TPlayer);
	rect.w = 64;
	rect.h = 64;

	rectAnim = {0, 0, 64, 64};

	rectCollision.w = 32; 
	rectCollision.h = 32;
	rectCollision.x = rect.x + rect.w / 3;
	rectCollision.y = rect.y + rect.h / 3;
	velX = 0;
	velY = 0;

	posIniX = rect.x; //Lo inicializamos al valor que le pasan por parametro
	posIniY = rect.y;

	actualizaVectCols(); // Se va a llamar en play, en un for

	tipo = PJ;
	vida = 4;
	balas = 20;
	maximoBalas = 20;

	inmunidad = false;
	contadorInmunidad = 0;
}


Player::~Player()
{
}

void Player::draw() const {
	textura->drawAnimacion(pRenderer, rect.x - juego->camera.x, rect.y - juego->camera.y, rect, rectAnim);
}

void Player::animar(animacion current){ //derecha, izquierda, arriba, abajo
	switch (current)
	{
		case Player::derecha:
			rectAnim.y = 192; //Altura de la animacion		
			break;
		case Player::izquierda:
			rectAnim.y = 128; 		
			break;
		case Player::arriba:
			rectAnim.y = 64; 
			break;
		case Player::abajo:
			rectAnim.y = 0; 
			break;
		case Player::dchaUp:
			rectAnim.y = 320; 
			break;
		case Player::dchaDown:
			rectAnim.y = 256; 
			break;
		case Player::izdaUp:
			rectAnim.y = 384; 	
			break;
		case Player::izdaDown:
			rectAnim.y = 448; 
			break;
		default:
			break;
	}
	
	animacionBasica();
}

void Player::animacionBasica(){ //Para el paso de frames
	if (rectAnim.x >= 192){
		rectAnim.x = 0;
	}
	else {
		rectAnim.x += 64;
	}	
}

void Player::actualizaVectCols(){
	
	//uint porque el .size() es un uint y puede haber perdidas de memoria
	for (uint i = 0; i < juego->arrayObjetos.size(); i++){
		if (juego->arrayObjetos[i]->getType() != PJ && juego->arrayObjetos[i]->getType() != PJ_WEAPON){
			vectColsPropiasObjeto.push_back(juego->arrayObjetos[i]); // Asignamos el puntero J a que apunte al puntero de i.
		}
	}

}
void Player::update(int delta) {
	//rect.x = rect.x - juego->camera.x;
	//rect.y = rect.y - juego->camera.y;

	//COMPROBAR AQUÍ LA COLISIÓN DEL JUGADOR CON TODO > LLAMAR CON UN FOR A CADA OBJETO DEL ARRAY
	//
	/*for (int i = 0; i < arrayObjetos.size(); ++i){
		if (juego->checkCollision(this, arrayObjetos[i]){

		onCollision(arrayObjetos[i]->GetType();    <--- EL DE PLAYER, le pasas el TIPO de lo que se ha colisionado
		arrayObjetos[i]-> onCollision (this);	 <---- this == Player

		}
		
		
	}*/	

	rect.x += juego->getVelX() * delta / 1.5f;
	rect.y += juego->getVelY() * delta / 1.5f;
	
	rectCollision.x = (rect.x + rect.w / 3) * delta;
	rectCollision.y = (rect.y + rect.h / 3) * delta;

	if (juego->touchesWall(this)){		
		//IDEA: Hacer un "rectangulo" delante del jugador y comprobar si ese rectangulo, y no el del jugador es el que se está colisionando
		//Porque si la condicion se mueve arriba entonces si está en contacto con la pared el jugador no se mueve.
		//Tendría el mismo principio que un raycast en Unity, para lo cual necesitariamos un enum de direcciones y en funcion de la 
		//direccion del jugador se gira el "ray" para que siempre esté en frente suya. El enum estaba hecho en el dash primigenio, no sé si en el dash dos está.

		//printf("Wall touched!\n");
		rect.x -= juego->getVelX() * delta;
		rect.y -= juego->getVelY() * delta;
	}

	setCamera(juego->camera);

	/// COMPROBAMOS LAS COLISIONES DEL JUGADOR CON SU VECTOR  ///
	for (int i = 0; i < juego->arrayObjetos.size(); ++i){
		if (juego->checkCollision(this, juego->arrayObjetos[i])){

			onCollision(juego->arrayObjetos[i]->getType());    //<-- - EL DE PLAYER, le pasas el TIPO de lo que se ha colisionado
			juego->arrayObjetos[i]->onCollision(this->getType());		   //<---- this == Player

		}
	}

	if (inmunidad) {
		if (contadorInmunidad < 100) contadorInmunidad++;
		else if (contadorInmunidad == 100)
		{
			inmunidad = false;
			contadorInmunidad = 0;
		}
	}

	
	//std::cout << "RECT X JUGADOR: " << rect.x << "\n";
	//std::cout << "CAMARA X: " << juego->camera.x << "\n";

	//Para la animación:

		contador += delta;
		if (contador >= 6){
			proceso();
			contador = 0;				
		}

		//Recargar balas
		if (balas <= 0){
			contador2 += delta;
			balas = 0;
			if (contador2 >= 200){
				balas = maximoBalas;
				contador2 = 0;
			}
		}
		//rectAnim.x = rect.x;
		//rectAnim.y = rect.y;
} 
void Player::proceso(){
	//ANIMACION

	if (juego->getVelX() > 0 && juego->getVelY() == 0){
		animar(derecha);
	}
	if (juego->getVelX() < 0 && juego->getVelY() == 0){
		animar(izquierda);
	}
	if (juego->getVelY() < 0 && juego->getVelX() == 0){
		animar(arriba);
	}
	if (juego->getVelY()  > 0 && juego->getVelX() == 0){
		animar(abajo);
	}
	if (juego->getVelX()  > 0 && juego->getVelY() < 0){
		animar(dchaUp);
	}
	if (juego->getVelX() > 0 && juego->getVelY() > 0){
		animar(dchaDown);
	}
	if (juego->getVelX() < 0 && juego->getVelY()  < 0){
		animar(izdaUp);
	}
	if (juego->getVelX()  < 0 && juego->getVelY()  > 0){
		animar(izdaDown);
	}

	if (juego->getVelX() == 0 && juego->getVelY() == 0){
		contador = 0;
		rectAnim.x = 0;
	}
}

bool Player::onClick() {


	//Posiciones del ratón
	int mX, mY, posX, posY;
	juego->getMousePos(mX, mY);

	posX = rect.x + rect.w / 2;
	posY = rect.y + rect.h / 2;

	int distance = sqrt((mX - posX)*(mX - posX) + (mY - posY)*(mY - posY));

	int vX = 75 * (mX - posX) / distance;
	int vY = 75 * (mY - posY) / distance;

	//Disparo
	//juego->arrayBalas.push_back(new BalaPlayer(juego, posX, posY, vX, vY));

	if (balas > 0){
		//static_cast <Play*> (juego->topEstado())->newDisparo(this, rect.x + rect.w / 2, rect.y + rect.h / 2);
		juego->arrayBalas.push_back(new BalaPlayer(juego, posX, posY, vX, vY));
		balas--;
		//std::cout << balas << "\n";
		return true;
	}
	else return false;
	
	
}

void Player::getPos(int& x, int& y) {
	x = rect.x;
	y = rect.y;
}


void Player::gestorVida()
{
	if (!inmunidad) {
		vida--;
		cout << vida << "\n";
		inmunidad = true;
	}

	if (vida <= 0){

		//Se le posiciona en el checkpoint con la vida y las balas restauradas
		if (static_cast <Checkpoint*>(juego->arrayObjetos[1])->getCogido()){
			SDL_Rect aux;
			aux = juego->arrayObjetos[1]->getRect();
			rect.x = aux.x;
			rect.y = aux.y;
			rectCollision.x = aux.x;
			rectCollision.y = aux.y;
			vida = 4;
			balas = 20;		
		} else {
			rect.x = 200;
			rect.y = 200;
			vida = 4;
			balas = 20;
		}

		//dead = true; << PARA PROBAR EL CHECKPOINT 
	}
}

void Player::onCollision(collision infoCol){
	//En función del infoCol, de su tipo, el jugador hará unas cosas u otras que se definirán aquí. Se usa.
		gestorVida();

}

void Player::setCamera(SDL_Rect& camera)
{
	//Center the camera over the dot
	camera.x = (rect.x + rect.w / 2) - camera.w / 2;
	camera.y = (rect.y + rect.h / 2) - camera.h / 2;
	
	//Keep the camera in bounds
	if (camera.x < 0)
	{
		camera.x = 0;
	}
	if (camera.y < 0)
	{
		camera.y = 0;
	}
	if (camera.x > 2560 - camera.w)
	{
		camera.x = 2560 - camera.w;
	}
	if (camera.y > 7360 - camera.h)
	{
		camera.y = 7360 - camera.h;
	}
}
