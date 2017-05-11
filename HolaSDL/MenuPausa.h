#pragma once
#include "Estado.h"

class MenuPausa : public Estado
{
public:
	MenuPausa(Juego* ptr);
	~MenuPausa();

	bool active = false;
};

