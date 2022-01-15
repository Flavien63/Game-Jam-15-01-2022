#include "Plateforme.hpp"

bool Plateforme::actif = false;

Plateforme::Plateforme(int new_posA, int new_posB):
	posA(new_posA), posB(new_posB)
{}

void Plateforme::rendreActif()
{
	actif = true;
}

bool Plateforme::estActif()
{
	return actif;
}