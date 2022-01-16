#include "Joueur.hpp"
#include "Perso.hpp"

Joueur::Joueur()
{}

Joueur::~Joueur()
{

}

void Joueur::CheckpointUp()
{
	checkpoint++;
}

void Joueur::CheckpointDown()
{
	checkpoint--;
}

int Joueur::getCheckpoint()
{
	return checkpoint;
}
