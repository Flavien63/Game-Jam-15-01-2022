#include "Controller.hpp"

Controller::Controller() : _joueur(), _map()
{
	//_map.chargerMap("nomfichier")
}

void Controller::MouvementPerso(int dirH, int dirV)
{
	/*
	if (glfwGetKey(Window, GLFW_KEY_D) == GLFW_PRESS)
	{	}
	*/
	_joueur.setVitx(dirH);
	_joueur.setVity(dirV);

}

void Controller::deplacementEntite()
{

	bool checkX, checkY = true;
	Entite e;
	Entite autre;

	int newPosX, newPosY, newPosXDroite, newPosYHaut;
	int newPosXgrid, newPosYgrid, newPosXgridDroite, newPosYgridHaut;


	for (int k = 0; k < Entite::getNbEntite(); ++k)
	{
		checkX, checkY = true;
		if (k == Entite::getNbEntite())
		{
			e = _joueur;
		}
		else
		{
			e = _map.getEntite(k);
		}

		 newPosX = (e.getPosx() + e.getVitx());
		 newPosY = (e.getPosy() + e.getVity());
		 newPosXDroite = (e.getPosx() + e.getVitx() + e.getLongueur());
		 newPosYHaut = (e.getPosy() + e.getVity() + e.getHauteur());

		 newPosXgrid = newPosX / _map.getLargeurBloc();
		 newPosYgrid = newPosY / _map.getLargeurBloc();
		 newPosXgridDroite = newPosXDroite / _map.getLargeurBloc();
		 newPosYgridHaut = newPosYHaut / _map.getLargeurBloc();

		checkX = !(_map.isBlocFixe(newPosXgrid, e.getPosy() / _map.getLargeurBloc())) &&
			!(_map.isBlocFixe(newPosXgridDroite, e.getPosy() / _map.getLargeurBloc()));
		checkY = !(_map.isBlocFixe(e.getPosx() / _map.getLargeurBloc(), newPosYgrid)) &&
			!(_map.isBlocFixe(e.getPosx() / _map.getLargeurBloc(), newPosYgridHaut));
		int i = 0;
		while ((checkX || checkY) && i < Entite::getNbEntite() - 1)
		{
			if (!(autre == e))
			{
				autre = _map.getEntite(i);
				checkX = checkX && !(newPosXDroite >= autre.getPosx() && newPosX <= autre.getPosx() + autre.getLongueur());
				checkY = checkY && !(newPosYHaut >= autre.getPosy() && newPosY <= autre.getPosy() + autre.getHauteur());
			}
			++i;
		}
		if (!checkX)
		{
			e.setVitx(0);
		}
		if (!checkY)
		{
			e.setVity(0);
		}
		e.deplacer();
	}
	

	
}

void Controller::afficherEntite()
{
	int joueurPosX = _joueur.getPosx();
	int joueurPosY = _joueur.getPosy();

	int entitePosX, entitePosY;

	for (int i = 0; i < Entite::getNbEntite() - 1; i++)
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


