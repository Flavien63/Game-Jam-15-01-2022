
#include "Item.h"

Item::Item(int largeur, int longeur, int posx, int posy, int typ) :
	Bloc(largeur, longeur, posx, posy, 0, 0)
{
	actif = true;
	type = typ;
}

int Item::getType() {
	return type;
}

void Item::setType(int typ) {
	type = typ;
}

void Item::rendreInactif()
{
	actif = false;
}

bool Item::isActif()
{
	return actif;
}
