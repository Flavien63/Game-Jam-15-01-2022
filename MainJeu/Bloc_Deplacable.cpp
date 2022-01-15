#include "Bloc_Deplacable.hpp"

bool Bloc_Deplacable::actif = false;

Bloc_Deplacable::Bloc_Deplacable()
{}

void Bloc_Deplacable::rendreActif()
{
	actif = true;
}

bool Bloc_Deplacable::estActif()
{
	return actif;
}