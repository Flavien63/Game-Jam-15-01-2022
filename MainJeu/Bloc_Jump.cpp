#include "Bloc_Jump.hpp"

bool Bloc_Jump::actif = false;

Bloc_Jump::Bloc_Jump(int largeur, int longeur, int posx, int posy):
	Bloc(largeur, longeur, posx, posy, 0, 0)	
{
	vit_saut = 10;
}

void Bloc_Jump::rendreActif()
{
	actif = true;
}

bool Bloc_Jump::isActif()
{
	return actif;
}