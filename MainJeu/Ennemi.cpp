#include "Ennemi.hpp"
#include "Perso.hpp"

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

void Ennemi::Interragir(Ennemi en, Bloc b)
{
	en.setVitesse(-en.getVitesse());				//l'ennemi rebrousse chemin lorsqu'il rencontre un obstacle
}
