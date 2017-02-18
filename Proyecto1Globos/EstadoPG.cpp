#include "EstadoPG.h"

EstadoPG::EstadoPG()
{
}


EstadoPG::~EstadoPG()
{
}


void EstadoPG::draw() const{
	for (unsigned int i = 0; i < vObjetos.size(); i++){
		vObjetos[i]->draw();
	}
}

void EstadoPG::onClick(){
		for (unsigned int i = 0; i < vObjetos.size(); i++){
			vObjetos[i]->onClick();
		}
}

void EstadoPG::freeObjects(){
	for (unsigned int i = 0; i < vObjetos.size(); i++){
		delete (vObjetos[i]);
	}
}