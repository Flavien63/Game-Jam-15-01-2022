#pragma once
#include "Bloc.hpp"

class Item : public Bloc
{
	bool actif;
	int type;

public:
	Item(int largeur, int longeur, int posx, int posy, int typ);
	void rendreInactif();
	bool isActif();
	int getType();
	void setType(int typ);
};

