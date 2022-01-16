#include "Checkpoint.hpp"

bool Checkpoint::actif = false;

Checkpoint::Checkpoint(int largeur, int longeur, int posx, int posy) :
	Bloc(largeur, longeur, posx, posy, 0, 0)
{
}

void Checkpoint::rendreActif()
{
	actif = true;
}

bool Checkpoint::isActif()
{
	return actif;
}