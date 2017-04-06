#include "BossRino.h"


BossRino::BossRino(Juego* ptr, int px, int py) : enemy(ptr, px, py)
{
	textura = juego->getTextura(Juego::TBulletEnemy);

	vel = 6;
	freDis = 100;
	velDis = 20;

	rect.w = 50;
	rect.h = 50;

	rect.x = 100;
	rect.y = 100;

}


BossRino::~BossRino()
{
}

void BossRino::follow(int x, int y){
	int distance = sqrt((x - rect.x)*(x - rect.x) + (y - rect.y)*(y - rect.y));
	//int supa = rand() % 10;
	//std::cout << supa;
	if (distance > vel / 2) { //este numero es un margen de error que tendra que ir acorde con la velocidad del enemigo (vel)
		
		/*if (supa <= 1){
			vX = 2*vel * (x - rect.x) / distance;
			vY = 2*vel * (y - rect.x) / distance;
		}*/
		//else {
			vX = vel * (x - rect.x) / distance;
			vY = vel * (y - rect.y) / distance;
		//}
	}
	else {
		vX = 0;
		vY = 0;
	}
	/*if (supa = 0){
		rect.x += vX*3;
		rect.y += vY*3;
	}
	else{*/
		rect.x += vX;
		rect.y += vY;
	//}
	
}
void BossRino::follow2(int x, int y){
	int distance = sqrt((x - rect.x)*(x - rect.x) + (y - rect.y)*(y - rect.y));
	//int supa = rand() % 10;
	if (distance > vel / 2) { //este numero es un margen de error que tendra que ir acorde con la velocidad del enemigo (vel)
		vX = 3*vel * (x - rect.x) / distance;
		vY = 3*vel * (y - rect.y) / distance;
	}
	else {
		vX = 0;
		vY = 0;
	}
	/*if (supa = 0){
	rect.x += vX*3;
	rect.y += vY*3;
	}
	else{*/
	rect.x += vX;
	rect.y += vY;
	//}

}

void BossRino::update(int delta){
	int x, y;
	static_cast <Play*> (juego->topEstado())->posPlayer(x, y);
	++contDis;
	/*if (contDis < freDis - 20){ //Algo tope chungo para que se pare al disparar
		follow(x, y);
	}
	else if (contDis < freDis){
		follow2(x, y);
	}*/
	switch (humuluhumulu){
	case Estaditos::NORMAL:
		contAceleron = 0;
		++contDis;
		follow(x, y);
		if (contDis >= 100) humuluhumulu = Estaditos::PARADO;
		break;
	case Estaditos::ACELERON:
		contParado = 0;
		++contAceleron;
		follow2(posx, posy);
		if (contAceleron >= 30) humuluhumulu = Estaditos::NORMAL;
		break;
	case Estaditos::PARADO:
		contDis = 0;
		contParado++;
		if (contParado >= 50){
			sma();
			humuluhumulu = Estaditos::ACELERON; 
		}
		break;
	}
	

}
void BossRino::sma(){
	
	static_cast <Play*> (juego->topEstado())->posPlayer(posx, posy);
}
