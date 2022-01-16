#include "Map.hpp"

Map::Map() : _entites(nullptr)
{
	//memset(_matBlocFix, )
	for (int j = 0; j < _hauteurMap; j++)
	{
		for (int i = 0; i < _longueurMap; i++)
		{
			this->_mapBlocFix[j][i] = 0;
		}
	}
}

void Map::chargerMap(string path)
{
	ifstream monFlux(path);  // Ouverture d'un fichier en lecture

	int bloc;
	int i = 0; int j = 0;

	if (monFlux)
	{

		for (int i = 0; i < _hauteurMap; i++)
		{
			for (int j = 0; j < _longueurMap; j++)
			{
				monFlux >> bloc;
				cout << bloc;

				switch (bloc)
				{
				case Rien:
					_mapBlocFix[i][j] = 0; // Rien
					break;
				case BlocFixe:
					_mapBlocFix[i][j] = 1; // Bloc Fixe
					break;
				case BlocSpecialJump:
					//Bloc_Jump()
					cout << "Bloc jump" << endl;
					break;
				case BlocSpecialDeplacable:
					break;
					//case BlocSpecialPateforme: // Lu après la map
						//break;
				case BlockSpecialChekpoint:
					break;
				case BlockSpecialPic:
					break;
				case BlocSpecialItem:
					break;
				default:
					break;
				}
			}
			cout << endl;
		}

		int nbPlateformes;

		int nbFrames;
		int posAx, posAy, posBx, posBy;
		monFlux >> nbPlateformes; // Nombre de plateforme

		this->_entites = new Entite[nbPlateformes];

		for (int k = 0; k < nbPlateformes; k++)
		{
			monFlux >> nbFrames;
			monFlux >> posAx;
			monFlux >> posAy;
			monFlux >> posBx;
			monFlux >> posBy;

			//Plateforme(posAx, posAy, posAx, posAy, posBx, posBy, nbFrames);
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}

}

Entite Map::getEntite(int i)
{
	if (i < 0 || i >= 100)
	{
		cout << "Index en dehors du tableau d'entites" << endl;
	}
	else
	{
		return _entites[i];
	}
}

int Map::getLargeurBloc()
{
	return this->_largeurBloc;
}
