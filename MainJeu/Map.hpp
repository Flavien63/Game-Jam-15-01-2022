#ifndef __MAP_HPP__
#define __MAP_HPP__

class Bloc;
class Ennemi;
class Entite;

#include <string>
#include <iostream>
#include <fstream>

#include "Entite.hpp"
#include "Bloc_Jump.hpp"
#include "Bloc_Deplacable.hpp"
#include "Item.h"
#include "Plateforme.hpp"
#include "Pic.hpp"
#include "Checkpoint.hpp"

/*
class Bloc{};
class Ennemi{};
*/



using namespace std;

class Map
{
private:
	const int _largeurBloc = 60;

	const int _longueurMap = 100;
	const int _hauteurMap = 50;
	int _mapBlocFix[50][100];

	const int _nbMaxEntites = 10;
	Entite * _entites ;

public:
	Map();
	void chargerMap(string path);
	Entite getEntite(int );
	int getLargeurBloc();
	bool isBlocFixe(int x, int y);

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