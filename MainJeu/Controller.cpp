#include "Controller.hpp"

Controller::Controller() : _joueur(), _map()
{
	
}

void Controller::MouvementPerso()
{
}

void Controller::deplacementPerso(Perso inPerso)
{
	
}

void Controller::afficherEntite()
{
	int joueurPosX = _joueur.getPosx();
	int joueurPosY = _joueur.getPosy();

	int entitePosX, entitePosY;

	for (int i = 0; i < Entite::getNbEntite - 1; i++)
	{
		entitePosX = _map.getEntite(i).getPosx();
		entitePosY = _map.getEntite(i).getPosy();

		if (abs(joueurPosX - entitePosX) < tailleEcranX
			&& abs(joueurPosY - entitePosY) < tailleEcranY)
		{
			// _map.getEntite(i).afficher(); // TA fonction Alexandre
		}

	}
}


