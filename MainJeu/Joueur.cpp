#include "Joueur.hpp"

Joueur::Joueur():
	checkpoint(0)
{
}

Joueur::~Joueur()
{

}

void Joueur::setCheckpoint(Checkpoint c)
{
	checkpoint = c;
}

Checkpoint Joueur::getCheckpoint()
{
	return checkpoint;
}
