#pragma once
#ifndef __ITEM_h__
#define __ITEM_h__


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


#endif // !__ITEM_h__