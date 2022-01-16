#include "Joueur.hpp"

Joueur::Joueur():
	checkpoint(0)
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

void Joueur::CheckpointRAZ()
{
	checkpoint=0;
}

int Joueur::getCheckpoint()
{
	return checkpoint;
}
