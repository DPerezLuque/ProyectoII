#pragma once
#include "Estado.h"

class MenuOpciones : public Estado
{
public:
	MenuOpciones(Juego * juego);
	virtual ~MenuOpciones();
};

