#ifndef __MAP_HPP__
#define __MAP_HPP__

class Bloc{};
class Ennemi{};
class Entite{};

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Map
{
private:
	const int _largeurBloc = 10;

	const int _longueurMap = 11;
	const int _hauteurMap = 4;
	int _matBlocFix[100][1000];

	const int _nbMaxEntites = 100;
	Entite _entites[100];

public:
	Map();
	void chargerMap(string path);
	Entite getEntite(int i);
	int getLargeurBloc();

};


enum BlocSpeciale
{
	Rien = 0,
	BlocFixe = 1,
	BlocSpecialJump = 2, // Bloc_Jump
	BlocSpecialDeplacable = 3, // Bloc_Deplacable
	BlocSpecialPateforme = 4, // Plateforme
	BlockSpecialChekpoint = 5, // ...
	BlockSpecialPic = 6, //...
	BlocSpecialItem = 7 // ...
};

#endif