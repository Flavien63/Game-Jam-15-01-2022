#include "generationMatrice.h"		

void ajoutBlocFixe(int x, int y, int height, int width, char * matrice)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			matrice[(y + i) * K + j + x] = '1';
		}
	}
}

void ajoutBlocSpecialJump(int x, int y, int height, int width, char *matrice)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			matrice[(y + i) * K + j + x] = '2';
		}
	}
}

void ajoutBlocSpecialDeplacable(int x, int y, int height, int width, char* matrice)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			matrice[(y + i) * K + j + x] = '3';
		}
	}
}

void ajoutblocSpecialPlateforme(int x, int y, int height, int width, char* matrice)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			matrice[(y + i) * K + j + x] = '4';
		}
	}
}

void ajoutBlocSpecialCheckpoint(int x, int y, int height, int width, char* matrice)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			matrice[(y + i) * K + j + x] = '5';
		}
	}
}

void ajoutBlocSpecialPic(int x, int y, int height, int width, char* matrice)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			matrice[(y + i) * K + j + x] = '6';
		}
	}
}

void ajoutBlocSpecialItem(int x, int y, int height, int width, char* matrice)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			matrice[(y + i) * K + j + x] = '7';
		}
	}
}

void ouvertureFichier()
{
	ofstream fichier("matriceChargement.txt", ios::out | ios::trunc);

	char c = ' ';

	if (fichier)
	{
		char* matrice = (char*)malloc(N * K * sizeof(char));
		if (matrice)
		{
			for (int i = 0; i < N * K; i++)
			{
				matrice[i] = '0';
			}

			ajoutBlocFixe(0, 45, 3, 100, matrice);
			ajoutBlocFixe(85, 35, 10, 2, matrice);
			ajoutBlocFixe(30, 43, 2, 4, matrice);
			ajoutBlocFixe(20, 40, 2, 5, matrice);
			ajoutBlocSpecialItem(21, 36, 3, 3, matrice);
			ajoutBlocSpecialDeplacable(75, 42, 3, 3, matrice);
		}
		else
			cerr << "Erreur de malloc sur la matrice" << endl;

		for (int i = 0; i < K * N; i++)
		{
			c = matrice[i];
			fichier.put(c);
			fichier.put(' ');
			if ((i != 0) && ((i + 1) % K == 0))
			{
				fichier.put('\n');
			}
		}
		fichier.close();

		free(matrice);
	}
	else
		cerr << "Erreur à l'ouverture du fichier" << endl;
}

int main(int, char**)
{
	ouvertureFichier();

	return 0;
}