#include "Plateforme.hpp"

bool Plateforme::actif = false;

Plateforme::Plateforme(int largeur, int longeur, int posx, int posy, int new_posAx, int new_posAy, int new_posBx, int new_posBy):
	Bloc(largeur, longeur, posx, posy, 0, 0)
{
	posAx = new_posAx;
	posAy = new_posAy;
	posBx = new_posBx;
	posBy = new_posBy;
}

void Plateforme::rendreActif()
{
	actif = true;
}

bool Plateforme::isActif()
{
	return actif;
}

void Plateforme::seDeplacer()
{
	if (this->getPosx() == posAx && this->getPosy() == posAy )
	{ }
}