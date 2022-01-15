#include "Ennemi.hpp"

Ennemi::Ennemi(Texture texture):
	vitesse(0), texture(texture)
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

void Ennemi::Interragir(Bloc b)
{
	vitesse = -vitesse;					//l'ennemi rebrousse chemin lorsqu'il rencontre un obstacle
}
