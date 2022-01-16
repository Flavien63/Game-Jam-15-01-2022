#include "Pic.hpp"

bool Pic::actif = false;

Pic::Pic(int largeur, int longeur, int posx, int posy) :
	Bloc(largeur, longeur, posx, posy, 0, 0)
{
}

void Pic::rendreActif()
{
	actif = true;
}

bool Pic::isActif()
{
	return actif;
}