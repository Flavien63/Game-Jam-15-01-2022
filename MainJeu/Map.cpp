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

	_entites = new Entite[_nbMaxEntites];

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
					_entites[Entite::getNbEntite() - 1] = Bloc_Jump(_largeurBloc, _largeurBloc, i * _largeurBloc, j * _largeurBloc);
					cout << "Bloc jump" << endl;
					break;
				case BlocSpecialDeplacable:
					_entites[Entite::getNbEntite() - 1] = Bloc_Deplacable(_largeurBloc, _largeurBloc, i * _largeurBloc, j * _largeurBloc);
					break;
					//case BlocSpecialPateforme: // Lu après la map
						//break;
				case BlockSpecialChekpoint:
					//_entites[Entite::getNbEntite() - 1] = Checkpoint(_largeurBloc, _largeurBloc, i * _largeurBloc, j * _largeurBloc);
					break;
				case BlockSpecialPic:
					//_entites[Entite::getNbEntite() - 1] = Pic(_largeurBloc, _largeurBloc, i * _largeurBloc, j * _largeurBloc);
					break;
				case BlocSpecialItem:
					monFlux >> bloc;
					//_entites[Entite::getNbEntite() - 1] = Item(_largeurBloc, _largeurBloc, i * _largeurBloc, j * _largeurBloc, bloc);
					break;
				default:
					break;
				}
			}
			cout << endl;
		}

		int nbPlateformes;

		int nbFrames;
		int posX, posY, posAx, posAy, posBx, posBy;
		monFlux >> nbPlateformes; // Nombre de plateforme


		for (int k = 0; k < nbPlateformes; k++)
		{
			monFlux >> posX;
			monFlux >> posY;
			monFlux >> posAx;
			monFlux >> posAy;
			monFlux >> posBx;
			monFlux >> posBy;
			monFlux >> nbFrames;

			Plateforme(_largeurBloc, _largeurBloc,
				posAx, posAy, posAx, posAy, posBx, posBy, nbFrames);
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

		return _entites[i];
	
}

int Map::getLargeurBloc()
{
	return this->_largeurBloc;
}

bool Map::isBlocFixe(int x, int y)
{
	return this->_mapBlocFix[y][x] == 1 ? true : false;
}