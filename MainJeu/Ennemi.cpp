#include "Ennemi.hpp"

Ennemi::Ennemi():
	vitesse(0)
{
}

Ennemi::~Ennemi()
{
}

int Ennemi::getVitesse()
{
	return vitesse;
}

void Ennemi::setVitesse(int val)
{
	vitesse = val;
}

void Ennemi::Interragir(Ennemi en)
{
	en.setVitesse(-en.getVitesse());				//l'ennemi rebrousse chemin lorsqu'il rencontre un obstacle
}
