#include "Plateforme.hpp"

bool Plateforme::actif = false;

Plateforme::Plateforme(int largeur, int longeur, int posx, int posy, int new_posAx, int new_posAy, int new_posBx, int new_posBy, int frame):
	Bloc(largeur, longeur, posx, posy, (new_posBx - new_posAx) / frame, (new_posBy - new_posAy) / frame)
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
	//Si on se trouve à l'une des extrémitées du trajet de la plateforme,
	//sens change de valeur pour que la plateforme effectue le trajet dans l'autre sens;
	if (this->getPosx() == posAx && this->getPosy() == posAy)
	{
		sens = 1;
	}
	else if (this->getPosx() == posBx && this->getPosy() == posBy)
	{
		sens = -1;
	}
	else
	{
		this->setPosx(this->getPosx() + sens * this->getVitx());
		this->setPosx(this->getPosy() + sens * this->getVity());
	}
}