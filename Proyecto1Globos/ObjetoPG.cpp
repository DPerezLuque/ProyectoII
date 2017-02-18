#include "ObjetoPG.h"

ObjetoPG::ObjetoPG()
{
}


ObjetoPG::~ObjetoPG()
{
}

bool ObjetoPG::dentro(int x, int y) const {
	if (((x >= pRect.x && x <= (pRect.x + pRect.w)) && (y >= pRect.y && (y <= pRect.y + pRect.h)))) return true;
	else return false;
}

void ObjetoPG::draw() const{
	if (visible)
		(pJuego->getTextura(Textura))->draw(pJuego->getRender(), pRect);
}
