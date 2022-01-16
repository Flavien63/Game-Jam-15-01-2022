#include "Bloc_Deplacable.hpp"

bool Bloc_Deplacable::actif = false;

Bloc_Deplacable::Bloc_Deplacable(int largeur, int longeur, int posx, int posy):
	Bloc(largeur, longeur, posx, posy, 0, 0)
{
}

void Bloc_Deplacable::rendreActif()
{
	actif = true;
}

bool Bloc_Deplacable::isActif()
{
	return actif;
}

void Bloc_Deplacable::deplacer()
{
	Entite::deplacer();
}