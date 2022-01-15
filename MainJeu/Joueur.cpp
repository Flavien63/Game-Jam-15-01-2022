#include "Joueur.hpp"

Joueur::Joueur(Texture texture):
	checkpoint(0), texture(texture)
{

}

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
