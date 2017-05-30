#include "Player.h"
#include "Checkpoint.h"
#include <iostream>


Player::Player(Juego* ptr, int px, int py) : Objeto(ptr, px, py)
{
	textura = juego->getTextura(Juego::TPlayer);
	rect.w = 64;
	rect.h = 64;
	sonido = juego->getEfecto(Juego::disparoPlayer);
	aliento = juego->getEfecto(Juego::aliento);
	rectAnim = {0, 0, 64, 64};

	rectCollision.w = 32; 
	rectCollision.h = 32;
	rectCollision.x = rect.x + rect.w / 3;
	rectCollision.y = rect.y + rect.h / 3;
	velX = 0;
	velY = 0;

	posIniX = rect.x; //Lo inicializamos al valor que le pasan por parametro
	posIniY = rect.y;

	tipo = PJ;
	vida = 4;
	balas = 20;
	maximoBalas = 20;

	inmunidad = colisionDecorativo = estaRalentizado = false;
	contadorInmunidad = contDashing  = contadorRalentizado = 0;
}


Player::~Player()
{
}

void Player::getStats(int &life, int &bullets, int &dash) {
	life = vida;
	bullets = balas;
	dash = getDash();
}


void Player::draw() const {
	textura->drawAnimacion(pRenderer, rect.x - juego->camera.x, rect.y - juego->camera.y, rect, rectAnim);
}

void Player::update(int delta) {
	
	if (!controlCinematica){

		if (juego->debugPlayer){
			cout << rect.x << ", " << rect.y << "\n";
			juego->setDebugBool(false);
		}


		SDL_Rect nextRect;
		nextRect = rectCollision;


		//Preguntamos si está ralentizado para saber si revertirlo o seguir
		if (estaRalentizado){

			if (contadorRalentizado >= 50){
				estaRalentizado = false;
				contadorRalentizado = 0;
			}
			else contadorRalentizado++;
		}


		if (juego->getDash()){
			rect.x += juego->getVelX() * 4 * delta / 1.5f;
			rect.y += juego->getVelY() * 4 * delta / 1.5f;

			//nextRect.x += juego->getVelX() * 4 * delta / 1.5f;
			//nextRect.y += juego->getVelY() * 4 * delta / 1.5f;

			++contDashing;
			if (contDashing >= 10){
				contDashing = 0;
				juego->setDash(false);
			}
		}
		else{

			//rect.x += juego->getVelX() * delta / 1.5f;
			//rect.y += juego->getVelY() * delta / 1.5f;		

			nextRect.x += juego->getVelX() * delta / 1.5f;
			nextRect.y += juego->getVelY() * delta / 1.5f;
			if (!juego->touchesWall(nextRect) && !estaRalentizado) {
				rect.x += juego->getVelX() * delta / 1.5f;
				rect.y += juego->getVelY() * delta / 1.5f;
			}

			if (estaRalentizado) {
				rect.x += ((juego->getVelX() / 4) * delta / 1.5f);
				rect.y += ((juego->getVelY() / 4) * delta / 1.5f);
			}
			/*else{
				rect.x += ((juego->getVelX()/4) * delta / 1.5f);
				rect.y += ((juego->getVelY()/4) * delta / 1.5f);

				}*/
		}
		//IDEA: Hacer un "rectangulo" delante del jugador y comprobar si ese rectangulo, y no el del jugador es el que se está colisionando
		//Porque si la condicion se mueve arriba entonces si está en contacto con la pared el jugador no se mueve.
		//Tendría el mismo principio que un raycast en Unity, para lo cual necesitariamos un enum de direcciones y en funcion de la 
		//direccion del jugador se gira el "ray" para que siempre esté en frente suya. El enum estaba hecho en el dash primigenio, no sé si en el dash dos está.

		rectCollision.x = (rect.x + rect.w / 3) * delta;
		rectCollision.y = (rect.y + rect.h / 3) * delta;

		if (juego->touchesWall(getRect()) || colisionDecorativo) {
			//printf("Wall touched!\n");
			if (juego->getDash()) {
				rect.x -= juego->getVelX() * 4 * delta / 1.5f;
				rect.y -= juego->getVelY() * 4 * delta / 1.5f;
			}
			else {
				rect.x -= juego->getVelX() * delta;
				rect.y -= juego->getVelY() * delta;
			}
			colisionDecorativo = false;						//Devolvemos el valor a false para que el jugador pueda salir de la colision
		}

		setCamera(juego->camera);

		if (inmunidad) {
			if (contadorInmunidad < inmunidadMAX) contadorInmunidad++;
			else
			{
				inmunidad = false;
				contadorInmunidad = 0;
			}
		}

		//std::cout << "RECT X JUGADOR: " << rect.x << "\n";
		//std::cout << "CAMARA X: " << juego->camera.x << "\n";

		//Para la animación:
		contadorFrames += delta;
		if (contadorFrames >= 6){
			proceso();
			contadorFrames = 0;
		}

		//Recargar balas
		if (balas <= 0){
			contadorRecarga += delta;
			balas = 0;
			if (contadorRecarga >= 70){
				balas = maximoBalas;
				contadorRecarga = 0;
			}
		}

		//Recargar manual
		if (juego->getRecargar()){
			contadorRecarga += delta;
			balas = 0;
			if (contadorRecarga >= 70){
				balas = maximoBalas;
				contadorRecarga = 0;
				juego->setRecargar(false);
			}
		}
		//rectAnim.x = rect.x;
		//rectAnim.y = rect.y;

		//Controlar cadencia de disparo
		if (disparo){
			conta += delta;
			if (conta >= 10){
				conta = 0;
				disparo = false;
			}
		}
	}
	
	//Si entra aqui, es porque estamos en la cinemática
	else {
		rect.x+=3; //Hay que ajustar las medidas pero más o menos eso: Avanza hacia la derecha
		rectCollision = rect;
		//Para la animación:
		contadorFrames += delta;
		if (contadorFrames >= 6){
			animar(derecha);
			contadorFrames = 0;
		}
	}
} 

bool Player::onClick() {
	
	//Posiciones del ratón
	int mX, mY, posX, posY;
	juego->getMousePos(mX, mY);

	SDL_Rect aux;
	aux.x = mX;
	aux.y = mY;
	aux.h = 1;
	aux.w = 1;

	//Comprobamos primero que el click se ha hecho sobre terreno clickeable 
	if (!juego->touchesWall(aux)) {

		posX = rect.x + rect.w / 2;
		posY = rect.y + rect.h / 2;

		int distance = sqrt((mX - posX)*(mX - posX) + (mY - posY)*(mY - posY));

		int vX = 75 * (mX - posX) / distance;
		int vY = 75 * (mY - posY) / distance;

		//Disparo
		//juego->arrayBalas.push_back(new BalaPlayer(juego, posX, posY, vX, vY));
		//cout << conta << "\n";
		if (balas > 0 && conta == 0) {
			disparo = true; //Controlar cadencia de disparo
			sonido->play();
			ObjetoJuego * newBala = new BalaPlayer(juego, posX, posY, vX, vY);
			juego->arrayObjetos.push_back(newBala);
			juego->playerBullets.push_back(newBala);
			balas--;
			//std::cout << balas << "\n";
			return true;
		}
	}
	return false;
	
	
}

void Player::gestorVida()
{
	if (!inmunidad) {
		vida--;
		//cout << vida << "\n";
		inmunidad = true;
	}

	if (vida == 1){
		aliento->play();
	}

	if (vida <= 0){

		dead = true;
		
		//juego->estado->changeCurrentState(GAME_OVER);

		/*//Se le posiciona en el checkpoint con la vida y las balas restauradas
		
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
		}*/

		//dead = true; << PARA PROBAR EL CHECKPOINT 
	}
}

void Player::onCollision(collision type){
	
	switch (type) {
	case ENEMY_WEAPON:
		//if (!escudo)
		gestorVida();
		//else escudo = false;   -> Porque implica que estaba a true y ha absorbido el golpe
		//Y luego seria quitar la imagen de la HUD, que se podria hacer con un bool realmente
		break;
	case ENEMY:
		gestorVida();
		break;

	case KEY:
		juego->tieneLlave = true;
		break;

	case PUERTA:
		if (!juego->getLlave()){
		colisionDecorativo = true;
		}
		break;
	case BOSS:
		gestorVida();
		break;
	case BOSS_CARGA:
		gestorVida();
		break;
	case BOTIQUIN:
		if (vida <4)				//Si la vida es mayor que 4, lo ponemos a 4.
			vida++;
		break;

		/*
	case ENERGIA:
		if (juego -> getDashCutre()) //o sea, si el dash está en cooldown
			->>> PONER EL DASH A TRUE DE FORMA AUTOMATICA Y TODO LO QUE ELLO IMPLIQUE
		break;
		*/
	case DECORATIVO:
		colisionDecorativo = true;
		break;
	case BALA_RALENTIZADORA:
		estaRalentizado = true;
		gestorVida();
		break;
	default:
		break;
	}

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

//TODO LO DE ANIMACION
void Player::proceso(){

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
		contadorFrames = 0;
		rectAnim.x = 0;
	}
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